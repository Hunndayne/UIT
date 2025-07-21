#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Date;

istream& operator>>(istream& is, Date& a);
ostream& operator<<(ostream& os, const Date& a);

class Date {
private:
    int ngay;
    int thang;
    int nam;

public:
    Date();
    Date(int d, int m, int y);

    static bool isLeapYear(int year);
    static bool isValidDate(int d, int m, int y);
    static int getDaysInMonth(int month, int year);

    int getNgay() const { return ngay; }
    int getThang() const { return thang; }
    int getNam() const { return nam; }

    void setNgay(int d) { ngay = d; }
    void setThang(int m) { thang = m; }
    void setNam(int y) { nam = y; }

    int getDateOfWeek() const;
    string getDayName() const;
    int toJulianDay() const;
    void fromJulianDay(int jd);

    void tangNgay(int n = 1);
    void giamNgay(int n = 1);
    void tangThang(int n = 1);
    void giamThang(int n = 1);
    void tangNam(int n = 1);
    void giamNam(int n = 1);

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    Date operator+(int days) const;
    Date operator-(int days) const;
    int operator-(const Date& other) const;



    friend istream& operator>>(istream& is, Date& a);
    friend ostream& operator<<(ostream& os, const Date& a);
};

Date::Date() : ngay(1), thang(1), nam(2000) {}

Date::Date(int d, int m, int y) {
    if (isValidDate(d, m, y)) {
        ngay = d;
        thang = m;
        nam = y;
    }
    else {
        ngay = 1;
        thang = 1;
        nam = 2000;
        
    }
}

bool Date::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::isValidDate(int d, int m, int y) {
    if (y < 1 || m < 1 || m > 12 || d < 1) return false;
    return d <= getDaysInMonth(m, y);
}

int Date::getDaysInMonth(int month, int year) {
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;
    case 4: case 6: case 9: case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 0;
    }
}

int Date::getDateOfWeek() const {
    int tempMonth = thang;
    int tempYear = nam;

    if (tempMonth < 3) {
        tempMonth += 12;
        tempYear--;
    }

    int K = tempYear % 100;
    int J = tempYear / 100;
    int h = (ngay + 13 * (tempMonth + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    return (h + 5) % 7 + 1;
}

string Date::getDayName() const {
    string days[] = { "", "Thu hai", "Thu ba", "Thu tu", "Thu nam", "Thu sau", "Thu bay", "Chủ nhat" };
    return days[getDateOfWeek()];
}

int Date::toJulianDay() const {
    int a = (14 - thang) / 12;
    int y = nam + 4800 - a;
    int m = thang + 12 * a - 3;
    return ngay + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

void Date::fromJulianDay(int jd) {
    int a = jd + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (146097 * b) / 4;
    int d = (4 * c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5 * e + 2) / 153;

    ngay = e - (153 * m + 2) / 5 + 1;
    thang = m + 3 - 12 * (m / 10);
    nam = 100 * b + d - 4800 + m / 10;
}

void Date::tangNgay(int n) {
    int jd = toJulianDay();
    jd += n;
    fromJulianDay(jd);
}

void Date::giamNgay(int n) {
    int jd = toJulianDay();
    jd -= n;
    fromJulianDay(jd);
}

void Date::tangThang(int n) {
    thang += n;
    while (thang > 12) {
        thang -= 12;
        nam++;
    }
    int maxDays = getDaysInMonth(thang, nam);
    if (ngay > maxDays) ngay = maxDays;
}

void Date::giamThang(int n) {
    thang -= n;
    while (thang < 1) {
        thang += 12;
        nam--;
    }
    int maxDays = getDaysInMonth(thang, nam);
    if (ngay > maxDays) ngay = maxDays;
}

void Date::tangNam(int n) {
    nam += n;
    if (thang == 2 && ngay == 29 && !isLeapYear(nam)) {
        ngay = 28;
    }
}

void Date::giamNam(int n) {
    nam -= n;
    if (thang == 2 && ngay == 29 && !isLeapYear(nam)) {
        ngay = 28;
    }
}

Date& Date::operator++() {
    tangNgay(1);
    return *this;
}

Date Date::operator++(int) {
    Date temp = *this;
    tangNgay(1);
    return temp;
}

Date& Date::operator--() {
    giamNgay(1);
    return *this;
}

Date Date::operator--(int) {
    Date temp = *this;
    giamNgay(1);
    return temp;
}

Date Date::operator+(int days) const {
    Date result = *this;
    result.tangNgay(days);
    return result;
}

Date Date::operator-(int days) const {
    Date result = *this;
    result.giamNgay(days);
    return result;
}

int Date::operator-(const Date& other) const {
    return this->toJulianDay() - other.toJulianDay();
}



istream& operator>>(istream& is, Date& a) {
    while (true) {
        cout << "Nhap ngay (day): ";
        is >> a.ngay;
        cout << "Nhap thang (month): ";
        is >> a.thang;
        cout << "Nhap nam (year): ";
        is >> a.nam;

        if (a.isValidDate(a.ngay, a.thang, a.nam)) {
            break;
        }
        else {
            cout << "Ngay thang nam khong hop le. Vui long nhap lai!" << endl;
        }
    }
    return is;
}

ostream& operator<<(ostream& os, const Date& a) {
    os << setfill('0') << setw(2) << a.ngay << "/"
        << setw(2) << a.thang << "/" << a.nam;
    return os;
}
int main() {
    Date a,c ;
    cin >> a;
    cout << a<< (Date::isLeapYear(a.getNam()) ==1?" Nam nhuan":" Nam khong nhuan");
    cout << "\nTang them mot ngay (Tang hau to): " << a++<<" la: "<< a.getDayName();
    cout << "\nGiam mot ngay(Tang hau to): " << a-- << " la: " << a.getDayName();
    cout << "\nTang mot ngay (Tang tien to): " << ++a << " la: " << a.getDayName();
    cout << "\nGiam mot ngay (Tang tien to): " << ++a << " la: " << a.getDayName();
    cout << "\nSo ngay can them";
    int b;
    cin >> b;
    cout << "\nSo ngay sau khi them " << b << " ngay la: " << a + b << " la: " << a.getDayName();
    cout << "\nNhập ngày: "; cin >> c;
    cout <<a<<" - "<<c<<" = " << a - c<<" ngay";
    int e=0,f=0,g=0;
    cout << "Nhap ngay, thang, nam can thay doi ngay a: "; cin >> e>>f>>g;
    a.setNgay(e);
    a.setThang(f);
    a.setNam(g);
    cout << a.getNgay() << "/" << a.getThang() << "/" << a.getNam();
    return 0;
}