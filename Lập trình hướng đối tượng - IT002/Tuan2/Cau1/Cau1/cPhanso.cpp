
#include "cPhanso.h"

cPhanso::cPhanso()
{
    m_iTuSo = 0;
    m_iMauSo = 1;
}

// Constructor với tử số
cPhanso::cPhanso(int iTuSo)
{
    m_iTuSo = iTuSo;
    m_iMauSo = 1;
}

// Constructor với tử số và mẫu số
cPhanso::cPhanso(int iTuSo, int iMauSo)
{
    m_iTuSo = iTuSo;
    m_iMauSo = iMauSo;
    if (m_iMauSo == 0)
    {
        m_iMauSo = 1;
    }
    Rutgon();
}

int cPhanso::LayTuSo()
{
	return m_iTuSo;
}

int cPhanso::LayMauSo()
{
	return m_iMauSo;
}

void cPhanso::DatTuSo(int iTuSo)
{
	m_iTuSo = iTuSo;
}

void cPhanso::DatMauSo(int iMauSo)
{
	m_iMauSo = iMauSo;
}

cPhanso cPhanso::operator+(const cPhanso& a)
{
	cPhanso c;

	c.m_iTuSo = this->m_iTuSo * a.m_iMauSo + a.m_iTuSo * this->m_iMauSo;
	c.m_iMauSo = this->m_iMauSo * a.m_iMauSo;
    c.Rutgon();
	return c;
}
cPhanso cPhanso::operator-(const cPhanso& a)
{
    cPhanso c;

    c.m_iTuSo = this->m_iTuSo * a.m_iMauSo - a.m_iTuSo * this->m_iMauSo;
    c.m_iMauSo = this->m_iMauSo * a.m_iMauSo;
    c.Rutgon();
    return c;
}

cPhanso cPhanso::operator*(const cPhanso& a)
{
    cPhanso c;
    c.m_iTuSo = this->m_iTuSo * a.m_iTuSo; 
    c.m_iMauSo = this->m_iMauSo * a.m_iMauSo;  
    c.Rutgon();
    return c;
}

cPhanso cPhanso::operator/(const cPhanso& a)
{
    if (a.m_iTuSo == 0)
    {
        cout << "Khong the chia cho 0!" << endl;
        return cPhanso(0, 1);
    }

    cPhanso c;
    c.m_iTuSo = this->m_iTuSo * a.m_iMauSo;
    c.m_iMauSo = this->m_iMauSo * a.m_iTuSo;
    c.Rutgon();
    return c;
}

void cPhanso::Rutgon()
{
    if (m_iTuSo == 0)
    {
        m_iMauSo = 1;
        return;
    }

    int ucln = UCLN(m_iTuSo, m_iMauSo);
    m_iTuSo /= ucln;
    m_iMauSo /= ucln;

    if (m_iMauSo < 0)
    {
        m_iTuSo = -m_iTuSo;
        m_iMauSo = -m_iMauSo;
    }
}

int cPhanso::UCLN(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void cPhanso::Xuat()
{
    if (m_iMauSo == 1)
        cout << m_iTuSo;
    else if (m_iTuSo == 0)
        cout << "0";
    else
        cout << m_iTuSo << "/" << m_iMauSo;
}

void cPhanso::Nhap()
{
    cout << "Nhap tu so: ";
    cin >> m_iTuSo;
    cout << "Nhap mau so: ";
    cin >> m_iMauSo;

    while (m_iMauSo == 0)
    {
        cout << "Mau so khong the bang 0. Nhap lai mau so: ";
        cin >> m_iMauSo;
    }

    Rutgon();
}

istream& operator>>(istream& is, cPhanso& ps)
{
    cout << "Nhap tu so: ";
    is >> ps.m_iTuSo;
    cout << "Nhap mau so: ";
    is >> ps.m_iMauSo;
    while (ps.m_iMauSo == 0)
    {
        cout << "Mau so khong the bang 0. Nhap lai mau so: ";
        is >> ps.m_iMauSo;
    }
    ps.Rutgon();
    return is;
}


ostream& operator<<(ostream& os, const cPhanso& ps)
{
    if (ps.m_iMauSo == 1)
        os << ps.m_iTuSo;
    else if (ps.m_iTuSo == 0)
        os << "0";
    else
        os << ps.m_iTuSo << "/" << ps.m_iMauSo;
    return os;
}
