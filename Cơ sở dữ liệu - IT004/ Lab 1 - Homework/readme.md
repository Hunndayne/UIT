# Báo cáo Thực hành Lab 1 - Homework


## Thông tin sinh viên

- **Họ và tên:** Trần Thanh Hùng
- **MSSV:** 23520580

#### 1. **Câu 51**: Hiển thị tất cả thông tin của bảng `ChuyenGia`.
```
SELECT * FROM ChuyenGia;
```
![Câu 51 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image1.png)

#### 2. **Câu 52**: Liệt kê họ tên và email của tất cả chuyên gia.
```
SELECT HoTen, Email FROM ChuyenGia;
```
![Câu 52 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image2.png)

#### 3. **Câu 53**: Hiển thị tên công ty và số nhân viên của tất cả các công ty.
```
SELECT TenCongTy, SoNhanVien FROM CongTy;
```
![Câu 53 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image3.png)

#### 4. **Câu 54**: Liệt kê tên các dự án đang trong trạng thái 'Đang thực hiện'.
```
SELECT TenDuAn FROM DuAn WHERE TrangThai = N'Đang thực hiện';
```
![Câu 54 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image4.png)

#### 5. **Câu 55**: Hiển thị tên và loại của tất cả các kỹ năng.
```
SELECT TenKyNang, LoaiKyNang FROM KyNang;
```
![Câu 55 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image5.png)

#### 6. **Câu 56**: Liệt kê họ tên và chuyên ngành của các chuyên gia nam.
```
SELECT HoTen, ChuyenNganh FROM ChuyenGia WHERE GioiTinh = N'Nam';
```
![Câu 56 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image6.png)

#### 7. **Câu 57**: Hiển thị tên công ty và lĩnh vực của các công ty có trên 150 nhân viên.
```
SELECT TenCongTy, LinhVuc FROM CongTy WHERE SoNhanVien > 150;
```
![Câu 57 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image7.png)

#### 8. **Câu 58**: Liệt kê tên các dự án bắt đầu trong năm 2023.
```
SELECT TenDuAn FROM DuAn WHERE YEAR(NgayBatDau) = 2023;
```
![Câu 58 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image8.png)

#### 9. **Câu 59**: Hiển thị tên kỹ năng thuộc loại 'Công cụ'.
```
SELECT TenKyNang FROM KyNang WHERE LoaiKyNang = N'Công cụ';
```
![Câu 59 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image9.png)

#### 10. **Câu 60**: Liệt kê họ tên và số năm kinh nghiệm của các chuyên gia có trên 5 năm kinh nghiệm.
```
SELECT HoTen, NamKinhNghiem FROM ChuyenGia WHERE NamKinhNghiem > 5;
```

![Câu 60 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image10.png)

#### 11. **Câu 61**: Hiển thị tên công ty và địa chỉ của các công ty trong lĩnh vực 'Phát triển phần mềm'.
```
SELECT TenCongTy, DiaChi FROM CongTy WHERE LinhVuc = N'Phát triển phần mềm';
```
![Câu 61 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image11.png)

#### 12. **Câu 62**: Liệt kê tên các dự án có ngày kết thúc trong năm 2023.
```
SELECT TenDuAn FROM DuAn WHERE YEAR(NgayKetThuc) = 2023;
```
![Câu 62 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image12.png)

#### 13. **Câu 63**: Hiển thị tên và cấp độ của các kỹ năng trong bảng `ChuyenGia_KyNang`.
```
SELECT (
   SELECT TenKyNang 
   FROM KyNang 
   WHERE KyNang.MaKyNang = ChuyenGia_KyNang.MaKyNang) AS TenKyNang,
   ChuyenGia_KyNang.CapDo
FROM ChuyenGia_KyNang;
```
![Câu 63 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image13.png)

#### 14. **Câu 64**: Liệt kê mã chuyên gia và vai trò trong các dự án từ bảng `ChuyenGia_DuAn`.
```
SELECT MaChuyenGia, VaiTro FROM ChuyenGia_DuAn;
```
![Câu 64 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image14.png)

#### 15. **Câu 65**: Hiển thị họ tên và ngày sinh của các chuyên gia sinh năm 1990 trở về sau.
```
SELECT HoTen, NgaySinh FROM ChuyenGia WHERE YEAR(NgaySinh) >= 1990;

```
![Câu 65 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image15.png)

#### 16. **Câu 66**: Liệt kê tên công ty và số nhân viên sắp xếp theo số nhân viên giảm dần.
```
SELECT TenCongTy, SoNhanVien FROM CongTy ORDER BY SoNhanVien DESC;
```
![Câu 66 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image16.png)

#### 17. **Câu 67**: Hiển thị tên dự án và ngày bắt đầu sắp xếp theo ngày bắt đầu tăng dần.
```
SELECT TenDuAn, NgayBatDau FROM DuAn ORDER BY NgayBatDau ASC;
```
![Câu 67 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image17.png)

#### 18. **Câu 68**: Liệt kê tên kỹ năng chỉ hiển thị mỗi tên một lần (loại bỏ trùng lặp).
```
SELECT DISTINCT TenKyNang FROM KyNang;
```
![Câu 68 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image18.png)

#### 19. **Câu 69**: Hiển thị họ tên và email của 5 chuyên gia đầu tiên trong danh sách.
```
SELECT TOP 5 HoTen, Email
FROM ChuyenGia;
```
![Câu 69 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image19.png)

#### 20. **Câu 70**: Liệt kê tên công ty có chứa từ 'Tech' trong tên.
```
SELECT TenCongTy FROM CongTy WHERE TenCongTy LIKE N'%Tech%';
```
![Câu 70 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image20.png)

#### 21. **Câu 71**: Hiển thị tên dự án và trạng thái không bao gồm các dự án đã hoàn thành.
```
SELECT TenDuAn, TrangThai FROM DuAn WHERE TrangThai != N'Hoàn thành';
```
![Câu 71 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image21.png)

#### 22. **Câu 72**: Liệt kê họ tên và chuyên ngành của các chuyên gia sắp xếp theo chuyên ngành và họ tên.
```
SELECT HoTen, ChuyenNganh FROM ChuyenGia ORDER BY ChuyenNganh, HoTen;
```
![Câu 72 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image22.png)

#### 23. **Câu 73**: Hiển thị tên công ty và lĩnh vực chỉ bao gồm các công ty có từ 100 đến 200 nhân viên.
```
SELECT TenCongTy, LinhVuc FROM CongTy WHERE SoNhanVien BETWEEN 100 AND 200;
```
![Câu 73 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image23.png)

#### 24. **Câu 74**: Liệt kê tên kỹ năng và loại kỹ năng sắp xếp theo loại kỹ năng giảm dần và tên kỹ năng tăng dần.
```
SELECT TenKyNang, LoaiKyNang FROM KyNang ORDER BY LoaiKyNang DESC, TenKyNang ASC;
```
![Câu 74 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image24.png)

#### 25. **Câu 75**: Hiển thị họ tên và số điện thoại của các chuyên gia có email sử dụng tên miền 'email.com'.

![Câu 75 Kết quả](https://raw.githubusercontent.com/Hunndayne/UIT/refs/heads/main/C%C6%A1%20s%E1%BB%9F%20d%E1%BB%AF%20li%E1%BB%87u%20-%20IT004/%20Lab%201%20-%20Homework/media/image25.png)
```
SELECT HoTen, SoDienThoai FROM ChuyenGia WHERE Email LIKE '%@email.com%';
```
