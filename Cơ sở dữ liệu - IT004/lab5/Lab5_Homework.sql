-- Câu hỏi và ví dụ về Triggers (101-110)

-- 101. Tạo một trigger để tự động cập nhật trường NgayCapNhat trong bảng ChuyenGia mỗi khi có sự thay đổi thông tin.

ALTER TABLE ChuyenGia
ADD NgayCapNhat DATETIME

CREATE TRIGGER Auto_update_date
ON ChuyenGia
AFTER UPDATE
AS
BEGIN
    UPDATE ChuyenGia
    SET NgayCapNhat = GETDATE()
    FROM ChuyenGia
    INNER JOIN Inserted ON ChuyenGia.MaChuyenGia = Inserted.MaChuyenGia;
END;

-- 102. Tạo một trigger để ghi log mỗi khi có sự thay đổi trong bảng DuAn.

--Tạo bảng log

CREATE TABLE DuAn_Log(
	MaLog int ,
	MaDuAn int,
	HanhDong NVARCHAR(200),
	GiaTriCu NVARCHAR(200),
	GiaTriMoi NVARCHAR(200),
	ThoiGianThayDoi datetime default getdate()
)

--TRIGGER
CREATE TRIGGER LogDuAn
ON DuAn
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
--insert
    IF EXISTS (SELECT 1 FROM Inserted) AND NOT EXISTS (SELECT 1 FROM Deleted)
    BEGIN
        INSERT INTO DuAn_Log (MaDuAn, HanhDong, GiaTriMoi)
        SELECT
            MaDuAn,
            'INSERT',
            CONCAT('TenDuAn=', TenDuAn, '; MaCongTy=', MaCongTy, '; NgayBatDau=', NgayBatDau, 
                   '; NgayKetThuc=', NgayKetThuc, '; TrangThai=', TrangThai)
        FROM Inserted;
    END;

--update

 IF EXISTS (SELECT 1 FROM Inserted) AND EXISTS (SELECT 1 FROM Deleted)
    BEGIN
        INSERT INTO DuAn_Log (MaDuAn, HanhDong,GiaTriCu, GiaTriMoi)
        SELECT
            i.MaDuAn,
            'UPDATE',
            CONCAT('TenDuAn=', d.TenDuAn, '; MaCongTy=', d.MaCongTy, '; NgayBatDau=', d.NgayBatDau, 
                   '; NgayKetThuc=', d.NgayKetThuc, '; TrangThai=', d.TrangThai),
            CONCAT('TenDuAn=', i.TenDuAn, '; MaCongTy=', i.MaCongTy, '; NgayBatDau=', i.NgayBatDau, 
                   '; NgayKetThuc=', i.NgayKetThuc, '; TrangThai=', i.TrangThai)
        FROM Inserted i
        INNER JOIN Deleted d ON i.MaDuAn = d.MaDuAn;
    END;
--delete
IF EXISTS (SELECT 1 FROM Deleted) AND NOT EXISTS (SELECT 1 FROM Inserted)
    BEGIN
        INSERT INTO DuAn_Log (MaDuAn, Action, OldValues)
        SELECT
            MaDuAn,
            'DELETE',
            CONCAT('TenDuAn=', TenDuAn, '; MaCongTy=', MaCongTy, '; NgayBatDau=', NgayBatDau, 
                   '; NgayKetThuc=', NgayKetThuc, '; TrangThai=', TrangThai)
        FROM Deleted;
    END;
END;

-- 103. Tạo một trigger để đảm bảo rằng một chuyên gia không thể tham gia vào quá 5 dự án cùng một lúc.
CREATE TRIGGER Limit_ChuyenGia_DuAn
ON ChuyenGia_DuAn
AFTER INSERT
AS
BEGIN
 IF EXISTS (
        SELECT MaChuyenGia
        FROM ChuyenGia_DuAn
        GROUP BY MaChuyenGia
        HAVING COUNT(MaDuAn) > 5
    )
	BEGIN
        RAISERROR (N'Chuyên gia không thể tham gia quá 5 dự án cùng một lúc.', 16, 1);
        ROLLBACK TRANSACTION;
    END
	
END;

-- 104. Tạo một trigger để tự động cập nhật số lượng nhân viên trong bảng CongTy mỗi khi có sự thay đổi trong bảng ChuyenGia.
CREATE TRIGGER AUTO_UPDATE_SoNhanVien
ON ChuyenGia
AFTER INSERT,DELETE
AS
BEGIN
IF EXISTS (SELECT * FROM INSERTED)
    BEGIN
        UPDATE CongTy
        SET SoNhanVien = (
            SELECT COUNT(*)
            FROM ChuyenGia
        )
        WHERE CongTy.MaCongTy IS NOT NULL;
    END;
 IF EXISTS (SELECT * FROM DELETED)
    BEGIN
        UPDATE CongTy
        SET SoNhanVien = (
            SELECT COUNT(*)
            FROM ChuyenGia
        )
        WHERE CongTy.MaCongTy IS NOT NULL;
    END;
	
END;

-- 105. Tạo một trigger để ngăn chặn việc xóa các dự án đã hoàn thành.
CREATE TRIGGER Prevent_completed_project
ON DuAn
INSTEAD OF DELETE
AS
BEGIN
	SET NOCOUNT ON;
	IF EXISTS (
		SELECT 1
		FROM deleted d
		JOIN DuAn DA ON d.MaDuAn = DA.MaDuAn
		WHERE DA.TrangThai = N'Hoàn thành'
	)
	BEGIN
		RAISERROR('Không thể xóa dự án đã hoàn thành', 16, 1);
		ROLLBACK TRANSACTION;
	END
	ELSE
	BEGIN
		DELETE FROM DuAn
		WHERE MaDuAn IN (
			SELECT MaDuAn
			FROM deleted
		)
	END
END;

-- 106. Tạo một trigger để tự động cập nhật cấp độ kỹ năng của chuyên gia khi họ tham gia vào một dự án mới.
CREATE TRIGGER Auto_Update_Skill_Level
ON ChuyenGia_DuAn
AFTER INSERT
AS
BEGIN
	FROM ChuyenGia_KyNang c
	UPDATE 
END;

-- 107. Tạo một trigger để ghi log mỗi khi có sự thay đổi cấp độ kỹ năng của chuyên gia.

--Tạo bảng LOG

CREATE TABLE SkillLog (
    LogID INT IDENTITY(1,1) PRIMARY KEY,
    MaChuyenGia INT,
    MaKyNang INT,
    OldCapDo INT,
    NewCapDo INT,
    ThoiGianThayDoi DATETIME DEFAULT GETDATE()
);

--Tạo trigger:
CREATE TRIGGER Log_Skill_Level
ON ChuyenGia_KyNang
AFTER UPDATE
AS
BEGIN
    SET NOCOUNT ON;

    -- Ghi log khi có sự thay đổi cấp độ kỹ năng
    INSERT INTO SkillLog (MaChuyenGia, MaKyNang, OldCapDo, NewCapDo, ThoiGianThayDoi)
    SELECT 
        d.MaChuyenGia, 
        d.MaKyNang, 
        d.CapDo AS OldCapDo, 
        i.CapDo AS NewCapDo, 
        GETDATE() AS ThoiGianThayDoi
    FROM DELETED d
    INNER JOIN INSERTED i 
        ON d.MaChuyenGia = i.MaChuyenGia AND d.MaKyNang = i.MaKyNang
    WHERE d.CapDo <> i.CapDo;
END;


-- 108. Tạo một trigger để đảm bảo rằng ngày kết thúc của dự án luôn lớn hơn ngày bắt đầu.

CREATE TRIGGER Check_End_Start_day
ON DuAn
AFTER INSERT
AS
BEGIN
	IF EXISTS(
		SELECT 1
		FROM inserted
		WHERE NgayKetThuc>NgayBatDau
	)
	BEGIN
		RAISERROR(N'Ngày kết thúc của dự án luôn lớn hơn ngày bắt đầu.',16,1)
		ROLLBACK TRANSACTION;
	END
END;
-- 109. Tạo một trigger để tự động xóa các bản ghi liên quan trong bảng ChuyenGia_KyNang khi một kỹ năng bị xóa.
CREATE TRIGGER AUTO_DELETE_ChuyenGia_KyNang
ON ChuyenGia_KyNang
AFTER DELETE
AS
BEGIN
	FROM ChuyenGia_KyNang CGKN
	DELETE CGKN
	INNER JOIN DELETED d ON CGKN CGKN.MaKyNang=d.MaKyNang
END;

-- 110. Tạo một trigger để đảm bảo rằng một công ty không thể có quá 10 dự án đang thực hiện cùng một lúc.
CREATE TRIGGER CHECK_MAX_PROJECT
ON DuAn
AFTER INSERT
AS
BEGIN
	IF EXISTS(
		SELECT MaCongTy
		FROM DuAn
		WHERE TrangThai=N'Đang thực hiện'
		GROUP BY MaCongTy
		HAVING COUNT(*)>10
	)
	BEGIN
        RAISERROR (N'Một công ty không thể có quá 10 dự án đang thực hiện cùng một lúc.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

-- Câu hỏi và ví dụ về Triggers bổ sung (123-135)

-- 123. Tạo một trigger để tự động cập nhật lương của chuyên gia dựa trên cấp độ kỹ năng và số năm kinh nghiệm.
CREATE TRIGGER AUTO_UPDATE_ChuyenGia_luong

-- 124. Tạo một trigger để tự động gửi thông báo khi một dự án sắp đến hạn (còn 7 ngày).

-- Tạo bảng ThongBao nếu chưa có
CREATE TABLE ThongBao (
    ThongBaoID INT IDENTITY(1,1) PRIMARY KEY,
    MaDuAn INT,
    NgayThongBao DATETIME DEFAULT GETDATE(),
    FOREIGN KEY (MaDuAn) REFERENCES DuAn(MaDuAn)
);

CREATE TRIGGER SEND_NOTI_DUE_PROJECT
ON DuAn
AFTER INSERT, UPDATE
AS
BEGIN
	INSERT INTO ThongBao(MaDuAn, NgayThongBao)

	SELECT 
	i.MaDuAn,
	GETDATE()
	FROM inserted i
	WHERE DATEDIFF(DAY, GETDATE(), i.NgayKetThuc) = 7
END;

-- 125. Tạo một trigger để ngăn chặn việc xóa hoặc cập nhật thông tin của chuyên gia đang tham gia dự án.
CREATE TRIGGER PREVENT_DELETE_UPDATE_CHUYENGIA
ON ChuyenGia
INSTEAD OF DELETE, UPDATE 
AS
BEGIN
	IF EXISTS(
		SELECT 1
		FROM (
			SELECT MaChuyenGia FROM deleted
			UNION
			SELECT MaChuyenGia FROM inserted
		) AS updated
        WHERE MaChuyenGia IN (
            SELECT CGDA.MaChuyenGia
            FROM ChuyenGia_DuAn CGDA
            JOIN DuAn DA ON CGDA.MaDuAn = DA.MaDuAn
            WHERE DA.TrangThai = N'Đang thực hiện'
        )
	)
	 BEGIN
        RAISERROR (N'Không thể xóa hoặc cập nhật thông tin của chuyên gia đang tham gia dự án "Đang thực hiện".', 16, 1);
        ROLLBACK TRANSACTION;
    END;
END;

-- 126. Tạo một trigger để tự động cập nhật số lượng chuyên gia trong mỗi chuyên ngành.

-- Tạo bảng ThongKeChuyenNganh nếu chưa có
CREATE TABLE ThongKeChuyenNganh (
    ChuyenNganh NVARCHAR(50) PRIMARY KEY,
    SoLuongChuyenGia INT DEFAULT 0
);

CREATE TRIGGER Update_SoLuong_ChuyenNganh
ON ChuyenGia
AFTER INSERT, DELETE, UPDATE
AS
BEGIN
    INSERT INTO ThongKeChuyenNganh (ChuyenNganh, SoLuongChuyenGia)
    SELECT ChuyenNganh, COUNT(*) AS SoLuongChuyenGia
    FROM ChuyenGia
    GROUP BY ChuyenNganh;

    PRINT N'Cập nhật số lượng chuyên gia theo chuyên ngành thành công.';
END;

-- 127. Tạo một trigger để tự động tạo bản sao lưu của dự án khi nó được đánh dấu là hoàn thành.

-- Tạo bảng DuAnHoanThanh nếu chưa có
CREATE TABLE DuAnHoanThanh (
    MaDuAn INT PRIMARY KEY,
    TenDuAn NVARCHAR(200),
    MaCongTy INT,
    NgayBatDau DATE,
    NgayKetThuc DATE,
    TrangThai NVARCHAR(50),
    NgaySaoLuu DATETIME DEFAULT GETDATE()
);

CREATE TRIGGER Backup_DuAn_Complete
ON DuAn
AFTER UPDATE
AS
BEGIN

    -- Chèn dữ liệu vào bảng DuAn_Backup nếu trạng thái được cập nhật thành "Hoàn thành"
    INSERT INTO DuAnHoanThanh (MaDuAn, TenDuAn, MaCongTy, NgayBatDau, NgayKetThuc, TrangThai, NgaySaoLuu)
    SELECT 
        i.MaDuAn, 
        i.TenDuAn, 
        i.MaCongTy, 
        i.NgayBatDau, 
        i.NgayKetThuc, 
        i.TrangThai,
        GETDATE()
    FROM INSERTED i
    JOIN DELETED d ON i.MaDuAn = d.MaDuAn
    WHERE d.TrangThai <> N'Hoàn thành' AND i.TrangThai = N'Hoàn thành';
END;


-- 128. Tạo một trigger để tự động cập nhật điểm đánh giá trung bình của công ty dựa trên điểm đánh giá của các dự án.



-- 129. Tạo một trigger để tự động phân công chuyên gia vào dự án dựa trên kỹ năng và kinh nghiệm.



-- 130. Tạo một trigger để tự động cập nhật trạng thái "bận" của chuyên gia khi họ được phân công vào dự án mới.



-- 131. Tạo một trigger để ngăn chặn việc thêm kỹ năng trùng lặp cho một chuyên gia.



-- 132. Tạo một trigger để tự động tạo báo cáo tổng kết khi một dự án kết thúc.


-- 133. Tạo một trigger để tự động cập nhật thứ hạng của công ty dựa trên số lượng dự án hoàn thành và điểm đánh giá.



-- 133. (tiếp tục) Tạo một trigger để tự động cập nhật thứ hạng của công ty dựa trên số lượng dự án hoàn thành và điểm đánh giá.


-- 134. Tạo một trigger để tự động gửi thông báo khi một chuyên gia được thăng cấp (dựa trên số năm kinh nghiệm).


-- 135. Tạo một trigger để tự động cập nhật trạng thái "khẩn cấp" cho dự án khi thời gian còn lại ít hơn 10% tổng thời gian dự án.


-- 136. Tạo một trigger để tự động cập nhật số lượng dự án đang thực hiện của mỗi chuyên gia.


-- 137. Tạo một trigger để tự động tính toán và cập nhật tỷ lệ thành công của công ty dựa trên số dự án hoàn thành và tổng số dự án.

-- 138. Tạo một trigger để tự động ghi log mỗi khi có thay đổi trong bảng lương của chuyên gia.

-- 139. Tạo một trigger để tự động cập nhật số lượng chuyên gia cấp cao trong mỗi công ty.


-- 140. Tạo một trigger để tự động cập nhật trạng thái "cần bổ sung nhân lực" cho dự án khi số lượng chuyên gia tham gia ít hơn yêu cầu.


