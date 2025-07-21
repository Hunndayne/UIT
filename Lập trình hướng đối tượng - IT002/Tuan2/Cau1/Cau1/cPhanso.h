#include "iostream"
#include <cmath>
using namespace std;

class cPhanso
{
private:
    int  m_iTuSo;
    int  m_iMauSo;
    void Rutgon();
    int UCLN(int a, int b);
public:
    cPhanso();
    cPhanso(int iTuSo);
    cPhanso(int iTuSo, int iMauSo = 1);
    int LayTuSo();
    int LayMauSo();
    void DatTuSo(int iTuso);
    void DatMauSo(int iMauSo);
    cPhanso operator + (const cPhanso& a);
    cPhanso operator - (const cPhanso& a);
    cPhanso operator * (const cPhanso& a);
    cPhanso operator / (const cPhanso& a);
    void Xuat();
    void Nhap();
    friend istream& operator>>(istream& is, cPhanso& ps);
    friend ostream& operator<<(ostream& os, const cPhanso& ps);
};