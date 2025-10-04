#include <iostream>

class Sophuc {
private:
    float a, b;

public:

    Sophuc() {
        a = 0;
        b = 0;
    };

    Sophuc(float x, float y) {
        a = x;
        b = y;
    }

    Sophuc operator+(const Sophuc &sp) {
        Sophuc c;
        c.a = this->a + sp.a;
        c.b = this->b + sp.b;
        return c;
    };

    Sophuc operator-(const Sophuc &sp) {
        Sophuc c;
        c.a = this->a - sp.a;
        c.b = this->b - sp.b;
        return c;
    };

    Sophuc operator*(const Sophuc &sp) {
        Sophuc c;
        c.a = (this->a * sp.a) - (this->b * sp.b);
        c.b = (this->a * sp.b) + (this->b * sp.a);
        return c;
    };

    Sophuc operator/(const Sophuc &sp) {
        Sophuc c;
        float mau_so = sp.a * sp.a + sp.b * sp.b;

        if (mau_so == 0) {
            std::cout << "Loi: Chia cho so phuc 0" << std::endl;
            c.a = 0;
            c.b = 0;
        } else {

            c.a = (this->a * sp.a + this->b * sp.b) / mau_so;
            c.b = (this->b * sp.a - this->a * sp.b) / mau_so;
        }
        return c;
    };

    friend std::istream &operator>>(std::istream &is, Sophuc &sp) {
        std::cout << "Nhap phan thuc: ";
        is >> sp.a;
        std::cout << "Nhap phan ao: ";
        is >> sp.b;
        return is;
    };


    friend std::ostream &operator<<(std::ostream &os, const Sophuc &sp) {

        if (sp.b >= 0) {
            os << sp.a << " + " << sp.b << "i";
        } else {
            os << sp.a << " - " << -sp.b << "i";
        }
        return os;
    }
};

int main() {
    Sophuc A, B;

    std::cin >> A;
    std::cin >> B;

    std::cout << "A = " << A << std::endl;
    std::cout << "B = " << B << std::endl;

    Sophuc tong = A + B;
    std::cout << "A + B = " << tong << std::endl;

    Sophuc hieu = A - B;
    std::cout << "A - B = " << hieu << std::endl;

    Sophuc tich = A * B;
    std::cout << "A * B = " << tich << std::endl;

    Sophuc thuong = A / B;
    std::cout << "A / B = " << thuong << std::endl;

    return 0;
}