-- Câu hỏi SQL từ cơ bản đến nâng cao, bao gồm trigger

-- Cơ bản:
--1. Liệt kê tất cả chuyên gia trong cơ sở dữ liệu.
SELECT *
FROM [dbo].[ChuyenGia]
--2. Hiển thị tên và email của các chuyên gia nữ.
SELECT HoTen, Email
FROM [dbo].[ChuyenGia]
WHERE GioiTinh = N'Nữ'
--3. Liệt kê các công ty có trên 100 nhân viên.
SELECT * 
FROM [dbo].[CongTy]
WHERE SoNhanVien>='100'
--4. Hiển thị tên và ngày bắt đầu của các dự án trong năm 2023.
SELECT TenDuAn, NgayBatDau
FROM [dbo].[DuAn]
WHERE YEAR(NgayBatDau)=2023

-- Trung cấp:
--6. Liệt kê tên chuyên gia và số lượng dự án họ tham gia.
SELECT ChuyenGia.HoTen, count(ChuyenGia.MaChuyenGia)
FROM ChuyenGia
JOIN ChuyenGia_DuAn on ChuyenGia_DuAn.MaChuyenGia = ChuyenGia.MaChuyenGia
GROUP BY ChuyenGia.HoTen
--7. Tìm các dự án có sự tham gia của chuyên gia có kỹ năng 'Python' cấp độ 4 trở lên.
SELECT [TenDuAn]
FROM [dbo].[DuAn]
JOIN [dbo].[ChuyenGia_DuAn] on ChuyenGia_DuAn.MaDuAn = DuAn.MaDuAn
JOIN [dbo].[ChuyenGia_KyNang] on ChuyenGia_KyNang.MaChuyenGia=ChuyenGia_DuAn.MaChuyenGia
JOIN KyNang on KyNang.MaKyNang = ChuyenGia_KyNang.MaKyNang
WHERE KyNang.TenKyNang='Python' and ChuyenGia_KyNang.CapDo>='4'

--8. Hiển thị tên công ty và số lượng dự án đang thực hiện.
SELECT CongTy.TenCongTy, COUNT(DuAn.MaDuAn) AS SoLuongDuAn
FROM CongTy
INNER JOIN DuAn ON DuAn.MaCongTy = CongTy.MaCongTy
WHERE DuAn.TrangThai = N'Đang thực hiện'
GROUP BY CongTy.TenCongTy;

--9. Tìm chuyên gia có số năm kinh nghiệm cao nhất trong mỗi chuyên ngành.

SELECT *
FROM ChuyenGia
WITH ChuyenGia_XepHang AS (
    SELECT 
        ChuyenNganh,
        HoTen,
        NamKinhNghiem,
        ROW_NUMBER() OVER (PARTITION BY ChuyenNganh ORDER BY NamKinhNghiem DESC) AS XepHang
    FROM ChuyenGia
)
SELECT ChuyenNganh, HoTen, NamKinhNghiem
FROM ChuyenGia_XepHang
WHERE XepHang = 1;

--10. Liệt kê các cặp chuyên gia đã từng làm việc cùng nhau trong ít nhất một dự án.

SELECT 
    CG1.HoTen AS ChuyenGia1,
    CG2.HoTen AS ChuyenGia2,
    DA.TenDuAn
FROM ChuyenGia_DuAn AS CGD1
JOIN ChuyenGia_DuAn AS CGD2 ON CGD1.MaDuAn = CGD2.MaDuAn AND CGD1.MaChuyenGia < CGD2.MaChuyenGia
JOIN ChuyenGia AS CG1 ON CGD1.MaChuyenGia = CG1.MaChuyenGia
JOIN ChuyenGia AS CG2 ON CGD2.MaChuyenGia = CG2.MaChuyenGia
JOIN DuAn AS DA ON CGD1.MaDuAn = DA.MaDuAn;

-- Nâng cao:
--11. Tính tổng thời gian (theo ngày) mà mỗi chuyên gia đã tham gia vào các dự án.

SELECT 
    CG.MaChuyenGia,
    CG.HoTen,
    SUM(DATEDIFF(DAY, CGDA.NgayThamGia, DA.NgayKetThuc)) AS TongSoNgayThamGia
FROM 
    ChuyenGia CG
JOIN 
    ChuyenGia_DuAn CGDA ON CG.MaChuyenGia = CGDA.MaChuyenGia
JOIN 
    DuAn DA ON CGDA.MaDuAn = DA.MaDuAn
GROUP BY 
    CG.MaChuyenGia, CG.HoTen
ORDER BY 
    TongSoNgayThamGia DESC;

--12. Tìm các công ty có tỷ lệ dự án hoàn thành cao nhất (trên 90%).
SELECT CT. TenCongTy
FROM [dbo].[CongTy] CT
LEFT JOIN DuAn DA on DA.MaCongTy= CT.MaCongTy
GROUP BY CT.TenCongTy, CT.MaCongTy
HAVING  SUM(CASE WHEN DA.TrangThai = N'Hoàn thành' THEN 1 ELSE 0 END) * 1.0 / COUNT(DA.MaDuAn) > 0.9;

--13. Liệt kê top 3 kỹ năng được yêu cầu nhiều nhất trong các dự án.
SELECT TOP 3  KN.TenKyNang, COUNT (*) AS Top3
FROM [dbo].[ChuyenGia_KyNang] CGKN
JOIN [dbo].[KyNang] KN ON KN.MaKyNang = CGKN.MaKyNang
JOIN [dbo].[ChuyenGia_DuAn] CGDA On CGDA.MaChuyenGia=CGKN.MaChuyenGia
GROUP BY KN.TenKyNang
ORDER BY Top3 DESC

--14. Tính lương trung bình của chuyên gia theo từng cấp độ kinh nghiệm (Junior: 0-2 năm, Middle: 3-5 năm, Senior: >5 năm).


--15. Tìm các dự án có sự tham gia của chuyên gia từ tất cả các chuyên ngành.
WITH DanhSachChuyenNganh AS (
    SELECT DISTINCT ChuyenNganh
    FROM ChuyenGia
),
DuAn_ChuyenNganh AS (
    SELECT 
        DA.MaDuAn,
        DA.TenDuAn,
        CG.ChuyenNganh
    FROM 
        DuAn DA
    JOIN 
        ChuyenGia_DuAn CGDA ON DA.MaDuAn = CGDA.MaDuAn
    JOIN 
        ChuyenGia CG ON CGDA.MaChuyenGia = CG.MaChuyenGia
)
SELECT 
    D.MaDuAn,
    D.TenDuAn
FROM 
    DuAn D
WHERE 
    NOT EXISTS (
        SELECT ChuyenNganh
        FROM DanhSachChuyenNganh
        EXCEPT
        SELECT ChuyenNganh
        FROM DuAn_ChuyenNganh DACN
        WHERE DACN.MaDuAn = D.MaDuAn
    );



---- Trigger:
--16. Tạo một trigger để tự động cập nhật số lượng dự án của công ty khi thêm hoặc xóa dự án.

CREATE TRIGGER TRG_TDSLDA
ON [dbo].[CongTy]
AFTER INSERT, DELETE
AS
BEGIN
	IF EXISTS(SELECT 1 FROM inserted)
	BEGIN
		UPDATE CongTy
		SET 
END;

--17. Tạo một trigger để ghi log mỗi khi có sự thay đổi trong bảng ChuyenGia.


--18. Tạo một trigger để đảm bảo rằng một chuyên gia không thể tham gia vào quá 5 dự án cùng một lúc.

--19. Tạo một trigger để tự động cập nhật trạng thái của dự án thành 'Hoàn thành' khi tất cả chuyên gia đã kết thúc công việc.


--20. Tạo một trigger để tự động tính toán và cập nhật điểm đánh giá trung bình của công ty dựa trên điểm đánh giá của các dự án.
