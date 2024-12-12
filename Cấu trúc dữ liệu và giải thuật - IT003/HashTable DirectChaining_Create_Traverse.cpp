/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;
#define M 100

struct NODE {
    int key;
    NODE* pNext;
};
// Khai báo kiểu con trỏ chỉ node
typedef NODE* NODEPTR;
typedef NODEPTR HASHTABLE[M];

NODE* CreateNode(int x) {
    NODE* p;
    p = new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}
void AddTail(NODE*& head, int x) {
    NODE* p = CreateNode(x);
    if (head == NULL) head = p;
    else {
        NODE* i = head;
        while (i->pNext != NULL) {
            i = i->pNext;
        }
        i->pNext = p;
    }
}

int HF(int numbucket, int key) { return key % numbucket; }

//###INSERT CODE HERE -
void CreateHashTable(HASHTABLE H, int &numbucket) {
    cin >> numbucket;
    for (int i = 0; i < numbucket;i++) {
        H[i] = NULL;
    }
    while (true) {
        int key = 0;
        cin >> key;
        if (key == -1) break;
        int x = HF(numbucket, key);
        AddTail(H[x], key);
    }
}
void Traverse(HASHTABLE H, int numbucket) {
    for (int i = 0; i < numbucket; i++) {
        NODE* temp = H[i];
        cout <<i;
        while (temp != NULL) {
            if (temp != NULL)
                cout << " --> ";
            cout << temp->key;
            temp = temp->pNext;
        }
        cout << endl;
    }
}
int main() {
    HASHTABLE H;
    int numbucket;

    CreateHashTable(H, numbucket);
    Traverse(H, numbucket);

    return 0;
}
