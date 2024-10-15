#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};

struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST& l) {
    l.pHead = nullptr;
    l.pTail = nullptr;
}

NODE* CreateNode(int n) {
    NODE* p = new NODE;
    p->info = n;
    p->pNext = nullptr;
    return p;
}

void addTail(LIST& l, NODE* p) {
    if (l.pHead == nullptr) {
        l.pHead = l.pTail = p;
    }
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void CreateList(LIST& l) {
    int n;
    cin >> n;
    while (n != -1) {
        NODE* p = CreateNode(n);
        addTail(l, p);
        cin >> n;
    }
}

bool isSorted(NODE* p) {
    if (p == nullptr || p->pNext == nullptr) return false;

    int firstValue = p->info;
    bool allEqual = true;

    NODE* temp = p;
    while (temp != nullptr) {
        if (temp->info != firstValue) {
            allEqual = false;
            break;
        }
        temp = temp->pNext;
    }
    if (allEqual) return false;

    while (p->pNext != nullptr) {
        if (p->info > p->pNext->info) {
            return false;
        }
        p = p->pNext;
    }
    return true;
}

int main() {
    LIST* L = new LIST;

    CreateEmptyList(*L);
    CreateList(*L);

    cout << boolalpha << isSorted(L->pHead);

    return 0;
}
