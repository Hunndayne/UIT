#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class vehicle {
private:
    string Chuxe;
    string Loaixe;
    double Giatrixe;
    int dungtich;
    double thue;

public:
    vehicle() {
        Chuxe = "";
        Loaixe = "";
        Giatrixe = 0.0;
        dungtich = 0;
        thue = 0.0;
    }

    vehicle(const vehicle& vh) {
        Chuxe = vh.Chuxe;
        Loaixe = vh.Loaixe;
        Giatrixe = vh.Giatrixe;
        dungtich = vh.dungtich;
        thue = vh.thue;
    }

    vehicle(string chu, string loai, double gia, int dungtichxl) {
        setChuxe(chu);
        setLoaixe(loai);
        setGiatrixe(gia);
        setDungtichxylanh(dungtichxl);
        tinhThue();
    }

    string getChuxe() {
        return Chuxe;
    }
    string getLoaixe() {
        return Loaixe;
    }
    double getGiatrixe() {
        return Giatrixe;
    }
    int getDungtich() {
        return dungtich;
    }
    double getThue() {
        return thue;
    }

    void setChuxe(string chu) {
        Chuxe = chu;
    }

    void setLoaixe(string loai) {
        Loaixe = loai;
    }

    void setGiatrixe(double gia) {
        if (gia >= 0) {
            Giatrixe = gia;
        }
        else {
            cout << "Gia tri xe phai >= 0. Dat gia tri mac dinh = 0\n";
            Giatrixe = 0;
        }
    }

    void setDungtichxylanh(int dungtichxl) {
        if (dungtichxl >= 0) { 
            dungtich = dungtichxl;
        }
        else {
            cout << "Dung tich xy lanh phai >= 0. Dat gia tri mac dinh = 0\n";
            dungtich = 0;
        }
    }

    void tinhThue() {
        if (this->dungtich < 100) {
            this->thue = this->Giatrixe * 0.01;
        }
        else if (this->dungtich >= 100 && this->dungtich < 200) {
            this->thue = this->Giatrixe * 0.03;
        }
        else if (this->dungtich >= 200) { 
            this->thue = this->Giatrixe * 0.05;
        }
    }

    friend istream& operator>>(istream& is, vehicle& vh) {
        cout << "Nhap chu xe: ";
        is.ignore();
        getline(is, vh.Chuxe);

        cout << "Nhap loai xe: ";
        getline(is, vh.Loaixe);

        cout << "Nhap tri gia xe (VND): ";
        is >> vh.Giatrixe;

        if (vh.Giatrixe < 0) {
            cout << "Gia tri xe phai >= 0. Dat gia tri mac dinh = 0\n";
            vh.Giatrixe = 0;
        }

        cout << "Nhap dung tich xy lanh (cc): ";
        is >> vh.dungtich;

        if (vh.dungtich < 0) {
            cout << "Dung tich xy lanh phai >= 0. Dat gia tri mac dinh = 0\n";
            vh.dungtich = 0;
        }

        vh.tinhThue();
        return is;
    }

    // Output operator overloading
    friend ostream& operator<<(ostream& os, const vehicle& vh) {
        os << "Chu xe: " << vh.Chuxe
            << "\nLoai xe: " << vh.Loaixe
            << "\nGia tri xe: " << fixed << setprecision(0) << vh.Giatrixe << " VND"
            << "\nDung tich xy lanh: " << vh.dungtich << " cc"
            << "\nThue truoc ba: " << fixed << setprecision(0) << vh.thue << " VND";
        return os;
    }
};

int main() {

    vehicle xe1("Nguyen Van A", "Honda Wave", 25000000, 110);
    vehicle xe2("Tran Thi B", "Yamaha Exciter", 50000000, 150);

    vehicle xe3;
    cout << "\nNhap thong tin xe thu 3" << endl;
    cin >> xe3;  


    cout <<endl<<endl<< xe1 << endl << endl;


    cout << xe2 << endl << endl;


    cout << xe3 << endl << endl;

    return 0;
}