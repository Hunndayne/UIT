#include "Date.h"
#include <iomanip>

// Constructors
Date::Date() : ngay(1), thang(1), nam(2000) {}

Date::Date(int d, int m, int y) {
    if (isValidDate(d, m, y)) {
        ngay = d;
        thang = m;
        nam = y;
    } else {
        ngay = 1;
        thang = 1;
        nam = 2000;
    }
}

// Utility methods
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

// Getters
int Date::getNgay() const { return ngay; }
int Date::getThang() const { return thang; }
int Date::getNam() const { return nam; }

// Setters
void Date::setNgay(int d) { 
    if (isValidDate(d, thang, nam)) ngay = d; 
}

void Date::setThang(int m) { 
    if (m >= 1 && m <= 12) {
        thang = m;
        int maxDays = getDaysInMonth(thang, nam);
        if (ngay > maxDays) ngay = maxDays;
    }
}

void Date::setNam(int y) { 
    if (y > 0) {
        nam = y;
        if (thang == 2 && ngay == 29 && !isLeapYear(nam)) {
            ngay = 28;
        }
    }
}

// Day of week calculation using Zeller's formula
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

    // Convert to 1-7 (Monday to Sunday)
    return (h + 5) % 7 + 1;
}

string Date::getDayName() const {
    string days[] = {"", "Thứ hai", "Thứ ba", "Thứ tư", "Thứ năm", "Thứ sáu", "Thứ bảy", "Chủ nhật"};
    return days[getDateOfWeek()];
}

// Julian day conversion - Fixed algorithm
int Date::toJulianDay() const {
    int a = (14 - thang) / 12;
    int y = nam - a;
    int m = thang + 12 * a - 3;
    return ngay + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 + 1720995;
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

// Date manipulation methods - Simplified approach
void Date::tangNgay(int n) {
    for (int i = 0; i < n; i++) {
        ngay++;
        int maxDays = getDaysInMonth(thang, nam);
        if (ngay > maxDays) {
            ngay = 1;
            thang++;
            if (thang > 12) {
                thang = 1;
                nam++;
            }
        }
    }
}

void Date::giamNgay(int n) {
    for (int i = 0; i < n; i++) {
        ngay--;
        if (ngay < 1) {
            thang--;
            if (thang < 1) {
                thang = 12;
                nam--;
            }
            ngay = getDaysInMonth(thang, nam);
        }
    }
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

// Arithmetic operators
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

// Comparison operators
bool Date::operator==(const Date& other) const {
    return ngay == other.ngay && thang == other.thang && nam == other.nam;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    return this->toJulianDay() < other.toJulianDay();
}

bool Date::operator<=(const Date& other) const {
    return *this < other || *this == other;
}

bool Date::operator>(const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}

// Stream operators
istream& operator>>(istream& is, Date& a) {
    while (true) {
        cout << "Nhap ngay: ";
        is >> a.ngay;
        cout << "Nhap thang: ";
        is >> a.thang;
        cout << "Nhap nam: ";
        is >> a.nam;

        if (a.isValidDate(a.ngay, a.thang, a.nam)) {
            break;
        } else {
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