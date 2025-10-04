#include <iostream>
using namespace std;

class cTiME {
private:
    int second;
    int minute;
    int hour;

public:
    cTiME() {
        hour = 0;
        minute = 0;
        second = 0;
    }
    
    cTiME(int h, int m, int sec) {
        hour = h;
        minute = m;
        second = sec;
    }

    int toSec() const {
        return hour * 3600 + minute * 60 + second;
    }

    void reformat(int total_seconds) {
        hour = total_seconds / 3600;
        minute = (total_seconds % 3600) / 60;
        second = total_seconds % 60;
    }

    friend istream& operator>>(istream& is, cTiME& ct) {
        is >> ct.hour >> ct.minute >> ct.second;
        return is;
    }

    friend ostream& operator<<(ostream& os, const cTiME& ct) {
        os << ct.hour << ":" << ct.minute << ":" << ct.second;
        return os;
    }

    cTiME& operator++() {
        this->reformat(this->toSec() + 1);
        return *this;
    }

    cTiME operator++(int) {
        cTiME temp = *this;
        ++(*this);
        return temp;
    }
    cTiME& operator--() {
        this->reformat(this->toSec() - 1);
        return *this;
    }
    cTiME& operator--(int) {
        cTiME temp = *this;
        --(*this);
        return temp;
    }
};

int main() {
    cTiME t(10, 59, 58);
    cout << "Thoi gian ban dau: " << t << endl;

    t++;
    cout << "Sau khi t++: " << t << endl;

    ++t;
    cout << "Sau khi ++t: " << t << endl;

    return 0;
}