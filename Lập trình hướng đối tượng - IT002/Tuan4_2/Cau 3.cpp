#include <iostream>
#include <iomanip>

class CTime {
private:
    int gio, phut, giay;

    void normalize() {
        long total_seconds = gio * 3600 + phut * 60 + giay;

        const long SECONDS_IN_DAY = 86400;
        total_seconds = ((total_seconds % SECONDS_IN_DAY) + SECONDS_IN_DAY) % SECONDS_IN_DAY;
        gio = total_seconds / 3600;
        phut = (total_seconds % 3600) / 60;
        giay = total_seconds % 60;
    }

public:
    CTime(int h = 0, int m = 0, int s = 0) : gio(h), phut(m), giay(s) {
        normalize();
    }

    CTime operator+(int seconds) const {
        return CTime(gio, phut, giay + seconds);
    }

    CTime operator-(int seconds) const {
        return CTime(gio, phut, giay - seconds);
    }

    CTime& operator++() {
        ++giay;
        normalize();
        return *this;
    }

    CTime operator++(int) {
        CTime temp(*this);
        ++(*this);
        return temp;
    }

    CTime& operator--() {
        --giay;
        normalize();
        return *this;
    }

    CTime operator--(int) {
        CTime temp(*this);
        --(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const CTime& t) {
        return os << std::setfill('0')
                  << std::setw(2) << t.gio << ":"
                  << std::setw(2) << t.phut << ":"
                  << std::setw(2) << t.giay;
    }

    friend std::istream& operator>>(std::istream& is, CTime& t) {
        std::cout << "Nhap gio: ";
        is >> t.gio;
        std::cout << "Nhap phut: ";
        is >> t.phut;
        std::cout << "Nhap giay: ";
        is >> t.giay;
        t.normalize();
        return is;
    }
    int getGio() const { return gio; }
    int getPhut() const { return phut; }
    int getGiay() const { return giay; }
};

int main() {

    CTime t1;
    CTime t2(10, 30, 45);
    CTime t3(25, 70, 80);


    std::cout << "t1 " << t1 << std::endl;
    std::cout << "t2 " << t2 << std::endl;
    std::cout << "t3 " << t3 << std::endl;
    std::cout << std::endl;

    CTime t4 = t2 + 3661;
    CTime t5 = t2 - 3661;

    std::cout << "t2: " << t2 << std::endl;
    std::cout << "t2 + 3661 giay: " << t4 << std::endl;
    std::cout << "t2 - 3661 giay: " << t5 << std::endl;
    std::cout << std::endl;

    CTime t6(23, 59, 58);

    std::cout << "++t6: " << ++t6 << std::endl;
    std::cout << "t6++: " << t6++ << std::endl;

    std::cout << "--t6: " << --t6 << std::endl;
    std::cout << "t6--: " << t6-- << std::endl;

    std::cout << std::endl;

    return 0;
}