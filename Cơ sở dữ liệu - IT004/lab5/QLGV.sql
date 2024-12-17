 
--9. Lớp trưởng của một lớp phải là học viên của lớp đó. 
CREATE TRIGGER CHECK_TRGLOP
ON LOP
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM LOP L
        LEFT JOIN HOCVIEN H
        ON L.TRGLOP = H.MAHV AND L.MALOP = H.MALOP
        WHERE H.MAHV IS NULL
    )
    BEGIN
        RAISERROR ('Lớp trưởng phải là học viên của lớp đó.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

--10. Trưởng khoa phải là giáo viên thuộc khoa và có học vị “TS” hoặc “PTS”. 
CREATE TRIGGER CHECK_TRGKHOA
ON KHOA
AFTER INSERT, UPDATE
AS
BEGIN
    -- Kiểm tra điều kiện trưởng khoa
    IF EXISTS (
        SELECT 1
        FROM KHOA K
        JOIN GIAOVIEN G
        ON K.TRGKHOA = G.MAGV
        WHERE G.MAKHOA != K.MAKHOA
           OR G.HOCVI NOT IN ('TS', 'PTS')
    )
    BEGIN
        RAISERROR ('Trưởng khoa phải là giáo viên thuộc khoa và có học vị “TS” hoặc “PTS”.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

--15. Học viên chỉ được thi một môn học nào đó khi lớp của học viên đã học xong môn học này. 
CREATE TRIGGER CHECK_HOC_XONG_THI
ON KETQUATHI
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM INSERTED KQ
        JOIN HOCVIEN HV ON KQ.MAHV = HV.MAHV
        JOIN GIANGDAY GD 
            ON HV.MALOP = GD.MALOP AND KQ.MAMH = GD.MAMH
        WHERE KQ.NGTHI < GD.DENNGAY
    )
    BEGIN
        RAISERROR ('Học viên chỉ được thi khi lớp đã học xong môn học này.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;


--16. Mỗi học kỳ của một năm học, một lớp chỉ được học tối đa 3 môn. 
CREATE TRIGGER TRG_CHECK_MON
ON GIANGDAY
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT GD.MALOP, GD.HOCKY, GD.NAM
        FROM GIANGDAY GD
        JOIN (SELECT MALOP, HOCKY, NAM, COUNT(*) AS SL_MON
              FROM GIANGDAY
              GROUP BY MALOP, HOCKY, NAM) COUNT_MON
        ON GD.MALOP = COUNT_MON.MALOP
        AND GD.HOCKY = COUNT_MON.HOCKY
        AND GD.NAM = COUNT_MON.NAM
        WHERE COUNT_MON.SL_MON > 3
    )
    BEGIN
        RAISERROR ('Một lớp chỉ được học tối đa 3 môn trong một học kỳ của năm học.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;


--17. Sỉ số của một lớp bằng với số lượng học viên thuộc lớp đó. 
CREATE TRIGGER CHECK_SISO
ON HOCVIEN
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    IF EXISTS (
        SELECT L.MALOP
        FROM LOP L
        JOIN (
            SELECT MALOP, COUNT(*) AS SL_HOCVIEN
            FROM HOCVIEN
            GROUP BY MALOP
        ) HV ON L.MALOP = HV.MALOP
        WHERE L.SISO != HV.SL_HOCVIEN
    )
    BEGIN
        RAISERROR ('Sĩ số của lớp không khớp với số lượng học viên thuộc lớp đó.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;
--18. Trong quan hệ DIEUKIEN giá trị của thuộc tính MAMH và MAMH_TRUOC trong cùng một bộ không được giống nhau (“A”,”A”) và cũng không tồn tại hai bộ (“A”,”B”) và (“B”,”A”). 

CREATE TRIGGER CHECK_DIEUKIEN
ON DIEUKIEN
AFTER INSERT, UPDATE
AS
BEGIN
    -- Kiểm tra điều kiện 1: MAMH và MAMH_TRUOC không được giống nhau
    IF EXISTS (
        SELECT 1
        FROM INSERTED
        WHERE MAMH = MAMH_TRUOC
    )
    BEGIN
        RAISERROR ('MAMH và MAMH_TRUOC không được giống nhau.', 16, 1);
        ROLLBACK TRANSACTION;
        RETURN;
    END

    -- Kiểm tra điều kiện 2: Không tồn tại cặp ngược chiều (A, B) và (B, A)
    IF EXISTS (
        SELECT 1
        FROM INSERTED I
        JOIN DIEUKIEN D
        ON I.MAMH = D.MAMH_TRUOC AND I.MAMH_TRUOC = D.MAMH
    )
    BEGIN
        RAISERROR ('Không được tồn tại cặp ngược chiều (A, B) và (B, A).', 16, 1);
        ROLLBACK TRANSACTION;
        RETURN;
    END
END;


--19. Các giáo viên có cùng học vị, học hàm, hệ số lương thì mức lương bằng nhau. 
CREATE TRIGGER TRG_CHECK_MUCLUONG
ON GIAOVIEN
AFTER INSERT, UPDATE
AS
BEGIN
    -- Kiểm tra điều kiện mức lương phải bằng nhau
    IF EXISTS (
        SELECT 1
        FROM GIAOVIEN G1
        JOIN GIAOVIEN G2
        ON G1.HOCVI = G2.HOCVI
        AND G1.HOCHAM = G2.HOCHAM
        AND G1.HESO = G2.HESO
        WHERE G1.MUCLUONG <> G2.MUCLUONG
        AND G1.MAGV <> G2.MAGV
    )
    BEGIN
        RAISERROR ('Các giáo viên có cùng học vị, học hàm, hệ số lương thì mức lương phải bằng nhau.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;
--20. Học viên chỉ được thi lại (lần thi >1) khi điểm của lần thi trước đó dưới 5. 
CREATE TRIGGER CHECK_THI_LAI
ON KETQUATHI
AFTER INSERT, UPDATE
AS
BEGIN
    -- Kiểm tra điều kiện: Thi lại chỉ khi điểm thi trước < 5
    IF EXISTS (
        SELECT I.MAHV, I.MAMH, I.LANTHI
        FROM INSERTED I
        JOIN KETQUATHI KQ
        ON I.MAHV = KQ.MAHV AND I.MAMH = KQ.MAMH AND I.LANTHI = KQ.LANTHI + 1
        WHERE KQ.DIEM >= 5
    )
    BEGIN
        RAISERROR ('Học viên chỉ được thi lại khi điểm của lần thi trước dưới 5.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;


--21. Ngày thi của lần thi sau phải lớn hơn ngày thi của lần thi trước (cùng học viên, cùng môn học). 
CREATE TRIGGER CHECK_NGAYTHI
ON KETQUATHI
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT I.MAHV, I.MAMH, I.LANTHI, I.NGTHI, KQ.NGTHI AS NGTHI_TRUOC
        FROM INSERTED I
        JOIN KETQUATHI KQ
        ON I.MAHV = KQ.MAHV AND I.MAMH = KQ.MAMH AND I.LANTHI = KQ.LANTHI + 1
        WHERE I.NGTHI <= KQ.NGTHI
    )
    BEGIN
        RAISERROR ('Ngày thi của lần thi sau phải lớn hơn ngày thi của lần thi trước.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;


--22. Khi phân công giảng dạy một môn học, phải xét đến thứ tự trước sau giữa các môn học (sau khi học xong những môn học phải học trước mới được học những môn liền sau). 
CREATE TRIGGER CHECK_THUTU_MONHOC
ON GIANGDAY
AFTER INSERT, UPDATE
AS
BEGIN

    IF EXISTS (
        SELECT I.MALOP, I.MAMH, I.TUNGAY, D.MAMH_TRUOC, GD.DENNGAY
        FROM INSERTED I
        JOIN DIEUKIEN D ON I.MAMH = D.MAMH
        LEFT JOIN GIANGDAY GD 
            ON I.MALOP = GD.MALOP AND D.MAMH_TRUOC = GD.MAMH
        WHERE GD.DENNGAY IS NULL OR GD.DENNGAY > I.TUNGAY
    )
    BEGIN
        RAISERROR ('Phân công giảng dạy không hợp lệ: Phải học xong các môn học trước.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

--23. Giáo viên chỉ được phân công dạy những môn thuộc khoa giáo viên đó phụ trách.
CREATE TRIGGER CHECK_GV_DAY_MON
ON GIANGDAY
AFTER INSERT, UPDATE
AS
BEGIN

    IF EXISTS (
        SELECT 1
        FROM INSERTED GD
        JOIN MONHOC MH ON GD.MAMH = MH.MAMH
        JOIN GIAOVIEN GV ON GD.MAGV = GV.MAGV
        WHERE MH.MAKHOA <> GV.MAKHOA
    )
    BEGIN
        RAISERROR ('Giáo viên chỉ được phân công dạy những môn thuộc khoa của mình phụ trách.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;
