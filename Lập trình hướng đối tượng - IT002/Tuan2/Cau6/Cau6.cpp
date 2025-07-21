// Cau6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class cString {
private:
    char* data;
    int i;
public:
    cString() {
        i = 0;
        data = new char[1];
        data[0] = '\0';
    }

    ~cString() {
        delete[] data;
        data = nullptr;
    }

    int geti() {
        return i;
    }

    void seti(int l) {
        i = l;
    }

    bool cpy(char* dest, int dest_size, const char* src) {
        if (dest == nullptr || src == nullptr || dest_size <= 0) {
            return false;
        }
        int j = 0;
        while (src[j] != '\0' && j < dest_size - 1) {
            dest[j] = src[j];
            j++;
        }
        dest[j] = '\0';
        if (src[j] != '\0') {
            return false;
        }
        return true;
    }

    bool cat(char* dest, int dest_size, const char* src) {
        if (dest == nullptr || src == nullptr || dest_size <= 0) {
            return false;
        }
        int dest_len = 0;
        while (dest[dest_len] != '\0' && dest_len < dest_size - 1) {
            dest_len++;
        }
        int j = 0;
        while (src[j] != '\0' && dest_len < dest_size - 1) {
            dest[dest_len] = src[j];
            dest_len++;
            j++;
        }

        dest[dest_len] = '\0';

        if (src[j] != '\0') {
            return false;
        }

        return true;
    }

    friend istream& operator>>(istream& is, cString& str) {
        char buffer[1000];
        cout << "Nhap chuoi: ";
        if (is.peek() == '\n') {
            is.ignore();
        }
        is.getline(buffer, 1000);
        str.i = strlen(buffer);
        delete[] str.data;
        str.data = new char[str.i + 1];
        str.cpy(str.data, str.i + 1, buffer);
        return is;
    }

    friend ostream& operator<<(ostream& os, const cString& a) {
        if (a.data) {
            os << a.data;
        }
        return os;
    }

    void Upper() {
        if (this->data) {
            for (int l = 0; l < i; ++l) {
                if (this->data[l] >= 'a' && this->data[l] <= 'z') {
                    this->data[l] = this->data[l] - 32;
                }
            }
        }
    }

    void Lower() {
        if (this->data) {
            for (int l = 0; l < i; ++l) {
                if (this->data[l] >= 'A' && this->data[l] <= 'Z') {
                    this->data[l] = this->data[l] + 32;
                }
            }
        }
    }

    void reverse() {
        if (this->data && i > 0) {
            int f = 0;
            char temp[1000];
            for (int l = i - 1; l >= 0; --l) {
                temp[f] = this->data[l];
                f++;
            }
            temp[f] = '\0'; 

            delete[] this->data;
            this->data = new char[i + 1];
            cpy(this->data, i + 1, temp);
        }
    }

    cString(const char* str) {
        if (str != nullptr) {
            i = strlen(str);
            data = new char[i + 1];
            cpy(data, i + 1, str);
        }
        else {
            i = 0;
            data = new char[1];
            data[0] = '\0';
        }
    }

    cString(const cString& str) {
        i = str.i;
        data = new char[i + 1];
        cpy(data, i + 1, str.data);
    }

    cString& operator+=(const cString& str) {
        int newLength = this->i + str.i;
        char* newData = new char[newLength + 1];

        cpy(newData, newLength + 1, this->data);

        cat(newData, newLength + 1, str.data);

        delete[] this->data;
        this->data = newData;
        this->i = newLength;

        return *this;
    }
    cString& operator+(const cString& str) {
        int newLength = this->i + str.i;
        char* newData = new char[newLength + 1];

        cpy(newData, newLength + 1, this->data);

        cat(newData, newLength + 1, str.data);

        delete[] this->data;
        this->data = newData;
        this->i = newLength;

        return *this;
    }
};

int main()
{
    cString a,b;
    cin >> a;
    cout << "\nChieu dai cua chuoi: " << a.geti() << endl;

    cout << "Chuoi goc: " << a << endl;

    a.Upper();
    cout << "Chuoi in hoa: " << a << endl;

    a.Lower();
    cout << "Chuoi in thuong: " << a << endl;

    a.reverse();
    cout << "Chuoi dao nguoc: " << a << endl;

    cin >> b;
    cString c = a + b;
    cout << "Sau khi noi cString: " << c << endl;

    // Test operator +=
    a += " -- day la phan them";
    cout << "Sau khi noi: " << a << endl;
    cout << "Chieu dai moi: " << a.geti() << endl;

    return 0;
}