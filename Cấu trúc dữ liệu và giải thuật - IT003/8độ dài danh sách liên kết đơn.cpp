#include <iostream>
using namespace std;

// Định nghĩa cấu trúc của một node
struct NODE {
    int data;
    NODE* next;
};

// Định nghĩa cấu trúc của danh sách
struct LIST {
    NODE* head; // Phần tử đầu của danh sách
};

// Hàm khởi tạo danh sách rỗng
void CreateEmptyList(LIST& l) {
    l.head = NULL; // Ban đầu danh sách trống
}

// Hàm tạo một node mới
NODE* CreateNode(int n) {
    NODE* p = new NODE; // Cấp phát bộ nhớ cho node mới
    p->data = n;        // Gán giá trị cho node
    p->next = NULL;     // Node mới không trỏ đến node nào khác
    return p;           // Trả về con trỏ đến node mới
}

// Hàm thêm một node vào đầu danh sách
void addHead(LIST& l, NODE* p) {
    if (l.head == NULL) {
        l.head = p;     // Nếu danh sách rỗng, node mới sẽ là node đầu tiên
    }
    else {
        p->next = l.head;   // Node mới trỏ đến node đầu hiện tại
        l.head = p;         // Cập nhật node đầu là node mới
    }
}

// Hàm đếm số lượng phần tử trong danh sách
int length(LIST& l) {
    int count = 0;
    NODE* current = l.head;
    while (current != NULL) {   // Duyệt qua danh sách
        count++;                // Tăng biến đếm mỗi khi gặp một node
        current = current->next; // Di chuyển tới node tiếp theo
    }
    return count;
}

// Hàm nhập các phần tử vào danh sách từ đầu vào
void CreateList(LIST& l) {
    int n;
    cin >> n;
    while (n != -1) {           // Kết thúc khi gặp giá trị -1
        NODE* p = CreateNode(n); // Tạo một node mới với giá trị n
        addHead(l, p);           // Thêm node vào đầu danh sách
        cin >> n;                // Nhập giá trị tiếp theo
    }
}

int main() {
    LIST L;
    CreateEmptyList(L);         // Khởi tạo danh sách rỗng

    CreateList(L);              // Nhập danh sách từ người dùng

    cout << length(L);          // In ra số lượng phần tử trong danh sách

    return 0;
}
