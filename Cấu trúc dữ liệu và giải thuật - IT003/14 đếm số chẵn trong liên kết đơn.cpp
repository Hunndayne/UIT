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
    NODE* pHead; // Thêm pHead để tương thích với hàm main
};

// Hàm khởi tạo danh sách rỗng
void CreateEmptyList(LIST& l) {
    l.head = NULL; // Ban đầu danh sách trống
    l.pHead = NULL; // Khởi tạo pHead bằng NULL
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
    l.pHead = l.head; // Cập nhật pHead để trỏ đến node đầu của danh sách
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

// Hàm đếm số lượng phần tử chẵn trong danh sách
int count_even(NODE* pHead) {
    int count = 0;
    NODE* c = pHead;
    while (c != NULL) {
        if (c->data % 2 == 0) { // Kiểm tra nếu phần tử là số chẵn
            count++;
        }
        c = c->next; // Di chuyển tới node tiếp theo
    }
    return count;
}

int main() {
    LIST L;
    CreateEmptyList(L);

    CreateList(L);
    cout << count_even(L.pHead);

    return 0;
}
