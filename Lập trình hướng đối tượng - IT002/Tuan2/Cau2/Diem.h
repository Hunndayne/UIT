#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    // Constructor
    Point();
    Point(double hoanhdo, double tungdo);


    void setPoint(double hoanhdo, double tungdo);

    // L?y t?a ??
    double getX() const;
    double getY() const;

    // Thay ??i t?a ??
    void setX(double hoanhdo);
    void setY(double tungdo);

    void Nhap();
    void Xuat() const;

    void TinhTien(double dx, double dy);


    friend istream& operator>>(istream& is, Point& p);
    friend ostream& operator<<(ostream& os, const Point& p);


    Point& operator=(const Point& a);
    Point operator+(const Point& a) const;
    Point operator-(const Point& a) const;
    bool operator==(const Point& a) const;
    bool operator!=(const Point& a) const;
};