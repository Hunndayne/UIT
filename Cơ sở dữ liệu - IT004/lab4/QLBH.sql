-- 19. Có bao nhiêu hóa đơn không phải của khách hàng đăng ký thành viên mua? 
SELECT COUNT(*)
FROM HOADON
WHERE MAKH IS NULL;

-- 20. Có bao nhiêu sản phẩm khác nhau được bán ra trong năm 2006. 
SELECT COUNT(DISTINCT MASP)
FROM CTHD
JOIN HOADON ON CTHD.SOHD = HOADON.SOHD
WHERE YEAR(NGHD) = 2006;

-- 21. Cho biết trị giá hóa đơn cao nhất, thấp nhất là bao nhiêu? 
SELECT MAX(TRIGIA) AS MaxInvoiceValue, MIN(TRIGIA) AS MinInvoiceValue
FROM HOADON;

-- 22. Trị giá trung bình của tất cả các hóa đơn được bán ra trong năm 2006 là bao nhiêu?
SELECT AVG(TRIGIA) AS AverageInvoiceValue
FROM HOADON
WHERE YEAR(NGHD) = 2006;
-- 23. Tính doanh thu bán hàng trong năm 2006. 
SELECT SUM(TRIGIA) AS TotalRevenue
FROM HOADON
WHERE YEAR(NGHD) = 2006;

-- 24. Tìm số hóa đơn có trị giá cao nhất trong năm 2006. 
SELECT TOP 1 WITH TIES h.SOHD
FROM HOADON h	
WHERE YEAR(h.NGHD) = 2006 
ORDER BY h.TRIGIA DESC

-- 25. Tìm họ tên khách hàng đã mua hóa đơn có trị giá cao nhất trong năm 2006. 
SELECT TOP 1 WITH TIES k.HOTEN 
FROM KHACHHANG k 
JOIN HOADON h 
ON k.MAKH = h.MAKH 
WHERE YEAR(h.NGHD) = 2006 
ORDER BY h.TRIGIA DESC

-- 26. In ra danh sách 3 khách hàng (MAKH, HOTEN) có doanh số cao nhất. 
SELECT TOP 3 k.MAKH, k.HOTEN 
FROM KHACHHANG k 
ORDER BY DOANHSO DESC
-- 27. In ra danh sách các sản phẩm (MASP, TENSP) có giá bán bằng 1 trong 3 mức giá cao nhất. 
SELECT TOP 3 WITH TIES s.MASP, s.TENSP 
FROM SANPHAM s 
ORDER BY s.GIA DESC
-- 28. In ra danh sách các sản phẩm (MASP, TENSP) do “Thai Lan” sản xuất có giá bằng 1 trong 3 mức 
SELECT s.MASP, s.TENSP
FROM SANPHAM s
WHERE s.NUOCSX = 'Thai Lan' AND s.GIA IN ( 
	SELECT TOP 3 GIA
	FROM SANPHAM 
	ORDER BY GIA DESC
)

-- giá cao nhất (của tất cả các sản phẩm). 
-- 29. In ra danh sách các sản phẩm (MASP, TENSP) do “Trung Quoc” sản xuất có giá bằng 1 trong 3 mức 
-- giá cao nhất (của sản phẩm do “Trung Quoc” sản xuất). 
SELECT TOP 3 WITH TIES sx.MASP, sx.TENSP
FROM SANPHAM sx
WHERE sx.NUOCSX = 'Trung Quoc'
ORDER BY sx.GIA DESC;


-- 30. * In ra danh sách 3 khách hàng có doanh số cao nhất (sắp xếp theo kiểu xếp hạng). 
SELECT TOP 3 *
FROM KHACHHANG k 
ORDER BY k.DOANHSO DESC

-- 31. Tính tổng số sản phẩm do “Trung Quoc” sản xuất. 
SELECT COUNT(*) SL
FROM SANPHAM s 
WHERE NUOCSX = 'Trung Quoc'
-- 32. Tính tổng số sản phẩm của từng nước sản xuất. 
SELECT s.NUOCSX, COUNT(*) AS 'SL San Pham' 
FROM SANPHAM s 
GROUP BY s.NUOCSX 
-- 33. Với từng nước sản xuất, tìm giá bán cao nhất, thấp nhất, trung bình của các sản phẩm. 
SELECT s.NUOCSX, MAX(s.GIA) AS 'CAO NHAT', MIN(s.GIA) AS 'Thap Nhat', AVG(s.GIA) AS 'Trung Binh'
FROM SANPHAM s 
GROUP BY s.NUOCSX 

-- 34. Tính doanh thu bán hàng mỗi ngày. 
SELECT h.NGHD, SUM(h.TRIGIA) AS 'Doanh Thu'
FROM HOADON h 
GROUP BY h.NGHD 
-- 35. Tính tổng số lượng của từng sản phẩm bán ra trong tháng 10/2006.
SELECT c.MASP, SUM(c.SL) AS 'So Luong'
FROM HOADON h
JOIN CTHD c ON h.SOHD = c.SOHD 
WHERE MONTH(h.NGHD) = 10 AND YEAR(h.NGHD) = 2006
GROUP BY c.MASP 
-- 36. Tính doanh thu bán hàng của từng tháng trong năm 2006. 
SELECT MONTH(h.NGHD), SUM(h.TRIGIA) AS 'Doanh Thu'
FROM HOADON h 
WHERE YEAR(h.NGHD) = 2006
GROUP BY MONTH(h.NGHD)
-- 37. Tìm hóa đơn có mua ít nhất 4 sản phẩm khác nhau. 
SELECT c.SOHD 
FROM CTHD c 
GROUP BY c.SOHD 
HAVING COUNT(*) >= 4
-- 38. Tìm hóa đơn có mua 3 sản phẩm do “Viet Nam” sản xuất (3 sản phẩm khác nhau). 
SELECT c.SOHD 
FROM CTHD c
JOIN SANPHAM s 
ON c.MASP = s.MASP 
WHERE s.NUOCSX = 'Viet Nam'
GROUP BY c.SOHD 
HAVING COUNT(DISTINCT c.MASP) >= 3
-- 39. Tìm khách hàng (MAKH, HOTEN) có số lần mua hàng nhiều nhất.  
SELECT k.MAKH, k.HOTEN 
FROM KHACHHANG k 
JOIN HOADON h 
ON k.MAKH = h.MAKH 
GROUP BY k.MAKH, k.HOTEN
HAVING COUNT(*) >= ALL (
	SELECT COUNT(*)
	FROM HOADON h2
	GROUP BY h2.MAKH
)

-- 40. Tháng mấy trong năm 2006, doanh số bán hàng cao nhất ? 
SELECT TOP 1 WITH TIES MONTH(h.NGHD) 
FROM HOADON h 
WHERE YEAR(h.NGHD) = 2006
GROUP BY MONTH(h.NGHD)
ORDER BY SUM(h.TRIGIA) DESC
-- 41. Tìm sản phẩm (MASP, TENSP) có tổng số lượng bán ra thấp nhất trong năm 2006.
SELECT TOP 1 WITH TIES s.MASP, s.TENSP 
FROM SANPHAM s, HOADON h, CTHD c 
WHERE s.MASP = c.MASP AND c.SOHD = h.SOHD AND YEAR(h.NGHD) = 2006
GROUP BY s.MASP, s.TENSP 
ORDER BY SUM(c.SL)
-- 42. *Mỗi nước sản xuất, tìm sản phẩm (MASP,TENSP) có giá bán cao nhất. 
SELECT s.NUOCSX, s.MASP, s.TENSP 
FROM SANPHAM s 
WHERE EXISTS (
	SELECT *
	FROM SANPHAM s2
	GROUP BY s2.NUOCSX 
	HAVING s.GIA = MAX(s2.GIA) AND s.NUOCSX = s2.NUOCSX 
)
-- 43. Tìm nước sản xuất sản xuất ít nhất 3 sản phẩm có giá bán khác nhau. 
SELECT s.NUOCSX 
FROM SANPHAM s 
GROUP BY s.NUOCSX 
HAVING COUNT(DISTINCT s.GIA) >= 3

-- 44. *Trong 10 khách hàng có doanh số cao nhất, tìm khách hàng có số lần mua hàng nhiều nhất. 
SELECT *
FROM KHACHHANG k 
WHERE k.MAKH IN (
	SELECT TOP 1 WITH TIES k2.MAKH
	FROM (SELECT TOP 10 MAKH FROM KHACHHANG ORDER BY DOANHSO DESC) AS k2
	JOIN HOADON h 
	ON k2.MAKH = h.MAKH 
	GROUP BY k2.MAKH
	ORDER BY COUNT(*) DESC
)