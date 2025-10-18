#include <iostream>
#include <string>


using namespace std;

string alphabetU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // khai báo 1 bảng chữ cái in hoa và in thường
string alphabetL = "abcdefghijklmnopqrstuvwxyz";

bool Contain(string s, char c) { // Hàm kiểm tra xem kí tự có tồn tại trong chuỗi không
    for (char ch : s)
        if (ch == c) return true;
    return false;
}


int VigenereAlg(char a, char b, string abet, int abetSize, bool mode) { //Hàm tính vị trí của c[i] (hoặc p[i]) trên bảng 
    int ans, count; // chế độ 0 là giải mã, 1 là mã hoá
    count = ans = 0;
    for (int i = 0; i < abetSize; i++) { // dùng 1 vòng lặp để tìm 2 vị trí: k[i] và p[i] (hoặc c[i]) trong bảng
        if (abet[i] == a or (abet[i] == b and mode == 1) ) { // Trường hợp p[i]+k[i] (của mã hoá cho p[i])
            ans += i;
            count++;
        }
        else if (abet[i] == b and mode == 0) { // Trường hợp c[i]-k[i] (của giải mã cho c[i])
            ans = ans - i + abetSize;
            count++;
        }
        if (count == 2) break;// tìm hết thì dừng
    }
    return ans%abetSize;
}

string Encrypt(string p, string abet, string k, int abetSize, int kSize) {
    string c = ""; 
    for (int i = 0; i < p.size(); i++) {
        if (Contain(abet, p[i])){ // kt nếu kí tự p[i] có tồn tại trong bảng ko
            c += abet[VigenereAlg(p[i], k[i % kSize], abet, abetSize, 1)]; // có thì giải mã
        }
        else { // nếu kí tự không có trong bảng thì GIỮ NGUYÊN ko hoán vị
            c += p[i];
        }
    }
    return c;
}

string Decrypt(string c, string abet, string k, int abetSize, int kSize) {
    string p = "";
    for (int i = 0; i < c.size(); i++) {
        if (Contain(abet, c[i])) { // tương tự trên
            p += abet[VigenereAlg(c[i], k[i % kSize], abet, abetSize, 0)]; // có thì mã hoá
        }
        else {
            p += c[i];
        }
    }
    return p;
}

int main() {

    string Ciphertext, Plaintext, Key, Alphabet;
    int mode, AlphabetSize, KeySize;
    cout << "Enter alphabet's mode\n0 for default using both upper and lower letters\n1 for Upper only\n2 for Lower only\n3 for custom\nhere: ";
    cin >> mode; // chọn chế độ của bảng chữ cái
    switch (mode) {
    case 0: // 0 thì áp dụng cả bảng chữ cái in hoa và thường
        Alphabet = alphabetU + alphabetL;
        break;
    case 1: // chỉ in hoa
        Alphabet = alphabetU;
        break;
    case 2: // chỉ in thường
        Alphabet = alphabetL;
        break;
    case 3: // bảng chữ cái tự do
        cout << "Enter Alphabets (recommend not using space): "; //khuyến nghị ko dùng cách (dùng vẫn được)
        cin.ignore();
        getline(cin, Alphabet);
        break;
    }
    AlphabetSize = Alphabet.size();

     cout << "Enter Key: "; // Nhập key
     cin.ignore();
     getline(cin, Key);
     KeySize = Key.size();
    
    cout << "Enter mode (0 for decryption, 1 for encryption): "; //Nhập chế độ, 0 là giải mã và 1 là mã hoá
    cin >> mode;
    if (mode) {
        cout << "Enter plaintext: ";
        cin.ignore();
        getline(cin, Plaintext);
        cout << "\nYour ciphertext: " +Encrypt(Plaintext, Alphabet, Key, AlphabetSize, KeySize);
    }
    else {
        cout << "Enter ciphertext: ";
        cin.ignore();
        getline(cin, Ciphertext);
        cout << "\nYour plaintext: " + Decrypt(Ciphertext, Alphabet, Key, AlphabetSize, KeySize);
    }

    return 0;
    
}
