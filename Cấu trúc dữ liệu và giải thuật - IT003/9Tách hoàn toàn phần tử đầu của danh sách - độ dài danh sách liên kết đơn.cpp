#include <iostream>
using namespace std;

// Cấu trúc của một node
struct NODE
{
    int info;
    NODE *pNext;
};

// Cấu trúc của một DSLK
struct LIST
{
    NODE *pHead;
    NODE *pTail;
};

// Tạo một node mới
NODE *CreateNode(int x)
{
    NODE *p = new NODE;
    p->info = x;
    p->pNext = NULL;
    return p;
}

// Tạo danh sách rỗng
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail = NULL;
}

// Thêm node vào cuối danh sách
void addTail(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void CreateList(LIST &l)
{
    int n = 0, x = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        NODE *p = CreateNode(x);
        addTail(l, p);
    }
}

NODE *SeparateHead(LIST &l)
{
    if (l.pHead == NULL)
        return NULL;
    NODE *p = l.pHead;
    l.pHead = l.pHead->pNext;
    if (l.pHead == NULL)
        l.pTail = NULL;
    return p;
}
// NODE* SeparateHead(LIST& L){

//     if(L.pHead == nullptr)

//         return nullptr;

//     NODE* p = L.pHead;

//     L.pHead = L.pHead->pNext;

//     if (L.pHead == nullptr)

//         L.pTail = nullptr;

//     p->pNext=NULL;

//     return p;

// }
void PrintList(NODE *pHead)
{
    if (pHead == NULL)
    {
        cout << "Empty List." << endl;
        return;
    }
    NODE *p = pHead;
    while (p != NULL)
    {
        cout << p->info;
        if (p->pNext != NULL)
            cout << " ";
        p = p->pNext;
    }
    cout << endl;
}

int main()
{
    LIST L;
    CreateEmptyList(L);

    // Nhập danh sách
    CreateList(L);

    // Tách phần tử đầu tiên
    NODE *p = SeparateHead(L);
    if (p != NULL)
        cout << p->info << endl;

    // In danh sách sau khi tách
    PrintList(L.pHead);

    return 0;
}
