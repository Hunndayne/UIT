#include "toimetquaincludemotlandi.h"
class donthuc {
private:
    double a;
    int n;
public:
    donthuc() {
        a = 0;
        n = 0;
    }
    donthuc(double a) {
        this->a = a;
    }
    donthuc(double a, int n) {
        this->a = a;
        this->n = n;
    }
    int xacdinhpt(int x0) {
        return a*pow(x0,n);
    }
    int nghiem(double b) {
        return pow((b/a),1/n);
    }
    donthuc operator+(const donthuc &d) {
        return donthuc(this->a+d.a);
    }
    friend ostream& operator<<(ostream& os, const donthuc& d) {

    }
    friend istream& operator>>(istream& is, donthuc& d) {
        do {
            is >> d.a;
            is >> d.n;
        }while (d.a!=0 && d.n>=1&&d.n<=100);
        return is;
    }
};