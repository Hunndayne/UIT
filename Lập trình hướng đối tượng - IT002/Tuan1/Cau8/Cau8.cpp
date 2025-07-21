#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDayOfWeek(int day, int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int K = year % 100;
    int J = year / 100;
    int h = (day + 13 * (month + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    return h; 
}

int main() {
    int day, month, year;

    cout << "Nhap ngay: ";
    cin >> day;
    cout << "Nhap thang: ";
    cin >> month;
    cout << "Nhap nam: ";
    cin >> year;

    if (year < 1) {
        cout << "Nam khong hop le." << endl;
        return 0;
    }
    if (month < 1 || month > 12) {
        cout << "Thang khong hop le." << endl;
        return 0;
    }

    int daysInMonth;
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
    default:
        daysInMonth = 0;
        break;
    }

    if (day < 1 || day > daysInMonth) {
        cout << "Ngay khong hop le." << endl;
        return 0;
    }

    int dayOfWeekZeller = getDayOfWeek(day, month, year);

    int finalDayOfWeek;
    switch (dayOfWeekZeller) {
    case 0: finalDayOfWeek = 6; break; 
    case 1: finalDayOfWeek = 0; break;
    case 2: finalDayOfWeek = 1; break;
    case 3: finalDayOfWeek = 2; break;
    case 4: finalDayOfWeek = 3; break; 
    case 5: finalDayOfWeek = 4; break;
    case 6: finalDayOfWeek = 5; break;
    }

    string days[] = { "Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau", "Thu Bay" };

    cout << "Ngay " << day << "/" << month << "/" << year << " la " << days[finalDayOfWeek] << "." << endl;

    return 0;
}