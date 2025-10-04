#include <iostream>
using namespace std;
class dathuc {
    private:
    double a;
    double b;
    public:
    dathuc(double a_, double b_) {
        if (a_==0) {
            return;
        }else{
        a=a_;
        b=b_;
        }
    }
    double fx(double x0) {
        return a*x0 + b;
    }
    double fx0() {
        return -b/a;
    }
    dathuc operator+(const dathuc &d) {
        double tempa, tempb;
        tempa=this->a+d.a;
        tempb=this->b+d.b;
        return dathuc(tempa,tempb);
    }
};

