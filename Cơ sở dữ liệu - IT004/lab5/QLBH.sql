	--11. Ngày mua hàng (NGHD) của một khách hàng thành viên sẽ lớn hơn hoặc bằng ngày khách hàng đó đăng ký thành viên (NGDK). 
CREATE TRIGGER Check_NGHD_NGDK
ON HOADON
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM inserted I
        JOIN KHACHHANG K ON I.MAKH = K.MAKH
        WHERE I.NGHD < K.NGDK -- NGÀY MUA HÀNG KHÔNG ĐƯỢC NHỎ HƠN NGÀY ĐĂNG KÝ
    )
    BEGIN
        RAISERROR('NGÀY MUA HÀNG KHÔNG ĐƯỢC NHỎ HƠN NGÀY ĐĂNG KÝ', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

	--12. Ngày bán hàng (NGHD) của một nhân viên phải lớn hơn hoặc bằng ngày nhân viên đó vào làm. 
CREATE TRIGGER Check_NGHD_NGVL
ON HOADON
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM INSERTED I
        JOIN NHANVIEN N ON I.MANV = N.MANV
        WHERE I.NGHD < N.NGVL
    )
    BEGIN
        RAISERROR ('Ngày bán hàng  không được nhỏ hơn ngày vào làm.', 16, 1);
        ROLLBACK TRANSACTION;
    END
END;

	--13. Trị giá của một hóa đơn là tổng thành tiền (số lượng*đơn giá) của các chi tiết thuộc hóa đơn đó. 
CREATE TRIGGER Update_TRIGIA
ON CTHD
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    UPDATE HOADON
    SET TRIGIA = (
        SELECT SUM(CT.SL * SP.GIA)
        FROM CTHD CT
        JOIN SANPHAM SP ON CT.MASP = SP.MASP
        WHERE CT.SOHD = HOADON.SOHD
    )
    WHERE SOHD IN (
        SELECT DISTINCT SOHD FROM INSERTED
        UNION
        SELECT DISTINCT SOHD FROM DELETED
    );
END;


	--14. Doanh số của một khách hàng là tổng trị giá các hóa đơn mà khách hàng thành viên đó đã mua.
CREATE TRIGGER Update_DOANHSO
ON HOADON
AFTER INSERT, UPDATE, DELETE
AS
BEGIN
    UPDATE KHACHHANG
    SET DOANHSO = (
        SELECT ISNULL(SUM(TRIGIA), 0)
        FROM HOADON
        WHERE HOADON.MAKH = KHACHHANG.MAKH
    )
    WHERE MAKH IN (
        SELECT DISTINCT MAKH FROM INSERTED
        UNION
        SELECT DISTINCT MAKH FROM DELETED
    );
END;
