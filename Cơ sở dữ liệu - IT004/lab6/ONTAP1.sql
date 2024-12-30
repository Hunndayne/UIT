-- Tạo cơ sở dữ liệu ONTAP1
CREATE DATABASE ONTAP1;




CREATE TABLE PHONGBAN (
    MaPhong CHAR(5) PRIMARY KEY,
    TenPhong VARCHAR(25),
    TruongPhong CHAR(5),
	ADD CONSTRAINT FK_PHONGBAN_NHANVIEN FOREIGN KEY (TruongPhong) REFERENCES  NHANVIEN(MaNV)
);


CREATE TABLE NHANVIEN (
    MaNV CHAR(5) PRIMARY KEY,
    HoTen VARCHAR(20),
    NgayVL SMALLDATETIME,
    HSLuong NUMERIC(4,2),
    MaPhong CHAR(5),
    CONSTRAINT FK_NHANVIEN_PHONGBAN FOREIGN KEY (MaPhong) REFERENCES PHONGBAN(MaPhong)
);


CREATE TABLE XE (
    MaXe CHAR(5) PRIMARY KEY,
    LoaiXe VARCHAR(20),
    SoChoNgoi INT,
    NamSX INT
);


CREATE TABLE PHANCONG (
    MaPC CHAR(5) PRIMARY KEY,
    MaNV CHAR(5),
    MaXe CHAR(5),
    NgayDi SMALLDATETIME,
    NgayVe SMALLDATETIME,
    NoiDen VARCHAR(25),
    FOREIGN KEY (MaNV) REFERENCES NHANVIEN(MaNV),
    FOREIGN KEY (MaXe) REFERENCES XE(MaXe)
);



--2. Hiện thực các ràng buộc toàn vẹn sau:  
--2.1. Năm sản xuất của xe loại Toyota phải từ năm 2006 trở về sau. (1.5 đ)  
CREATE TRIGGER CK_PRODUCT_YEAR_TOYOTA
ON XE
AFTER INSERT, UPDATE
AS
BEGIN
	IF EXISTS(
		SELECT 1
		FROM inserted
		WHERE LoaiXe = 'toyota' and NamSX<2006
	)
	BEGIN
	rollback transaction
	END
END;
--2.2. Nhân viên thuộc phòng lái xe “Ngoại thành” chỉ được phân công lái xe loại Toyota. (1.5 đ)  
CREATE TRIGGER CK_NT_TOYOTA
ON PHANCONG
AFTER INSERT, UPDATE
AS
BEGIN
	IF EXISTS(
		SELECT 1
		FROM inserted i
		JOIN NHANVIEN nv on i.MaNV = nv.MaNV
		JOIN PHONGBAN pb on nv.MaPhong=pb.MaPhong
		JOIN XE on i.MaXe=xe.MaXe
		WHERE pb.TenPhong=N'Ngoại Thành' and xe.LoaiXe<>'Toyota'
	)
	BEGIN 
	rollback transaction
	END
END;
--3. Viết các câu lệnh SQL thực hiện các câu truy vấn sau:  
--3.1. Tìm nhân viên (MaNV,HoTen) thuộc phòng lái xe “Nội thành” được phân công lái loại xe Toyota có số chỗ ngồi là 4. (1.5 đ)  
SELECT DISTINCT nv.MaNV,nv.HoTen
FROM NHANVIEN nv
Join PHONGBAN pb on nv.MaPhong = pb.MaPhong
JOIN PHANCONG pc on nv.MaNV=pc.MaNV
JOIN XE x on pc.MaXe=x.MaXe
WHERE x.SoChoNgoi = 4 AND pb.TenPhong = N'Nội thành' AND x.LoaiXe='Toyota'  
--3.2. Tìm nhân viên(MANV,HoTen) là trưởng phòng được phân công lái tất cả các loại xe. (1.5 đ)
SELECT nv.MaNV, nv.HoTen
FROM NHANVIEN as nv
JOIN PHONGBAN pb on nv.MaNV = pb.TruongPhong
JOIN PHANCONG pc on nv.MaNV = pc.MaNV
GROUP BY nv.MaNV, nv.HoTen
HAVING count(DISTINCT pc.MaXe)=(SELECT Count(MaXe) FROM XE)
--3.3. Trong mỗi phòng ban,tìm nhân viên (MaNV,HoTen) được phân công lái ít nhất loại xe Toyota. (1 đ)  
