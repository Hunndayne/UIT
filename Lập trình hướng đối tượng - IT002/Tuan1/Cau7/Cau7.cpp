#include <iostream>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void checkdate(int day, int month, int year) {
    int daysInMonth;

    if (month < 1 || month > 12) {
        cout << "Ngay khong hop le." << endl;
        return;
    }

    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        daysInMonth = 31;
        break;
    case 4: case 6: case 9: case 11:
        daysInMonth = 30;
        break;
    case 2: 
        daysInMonth = isLeapYear(year) ? 29 : 28;
        break;
    }

    if (day < 1 || day > daysInMonth) {
        cout << "Ngay khong hop le." << endl;
        return;
    }

    int nextDay = day + 1;
    int nextMonth = month;
    int nextYear = year;

    if (nextDay > daysInMonth) {
        nextDay = 1;
        nextMonth++;
        if (nextMonth > 12) {
            nextMonth = 1;
            nextYear++;
        }
    }

    cout << "Ngay ke tiep la: " << nextDay << "/" << nextMonth << "/" << nextYear << endl;
}

int main() {
    int day, month, year;

    cout << "Nhap ngay: ";
    cin >> day;
    cout << "Nhap thang: ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;

    checkdate(day, month, year);

    return 0;
}