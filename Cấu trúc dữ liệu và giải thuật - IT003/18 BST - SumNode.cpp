/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/

#include <iostream>
using namespace std;

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};
typedef TNODE* TREE;


void InsertNode(TREE& T, int x) {
    if (T == nullptr) {
        T = new TNODE;
        T->key = x;
        T->pLeft = T->pRight = nullptr;
    }
    else {
        if (x < T->key) {
            InsertNode(T->pLeft, x);
        }
        else if (x > T->key) {
            InsertNode(T->pRight, x);
        }

    }
}

void CreateTree(TREE& T) {
    T = nullptr;
    int value;
    bool isEmpty = true;


    while (cin >> value && value != -1) {
        isEmpty = false;
        InsertNode(T, value);
    }
}

//int SumNode(TREE T) {
//    if (T == NULL) {
//        return 0;
//    }
//    return T->key + SumNode(T->pLeft) + SumNode(T->pRight);
//}

int SumNode(TREE T) {
    if (T == nullptr) {
        return 0;
    }

    TNODE* current = T;
    int sum = 0;

    while (current != nullptr) {
        if (current->pLeft == nullptr) {
            sum += current->key;
            current = current->pRight;
        }
        else {
            TNODE* p = current->pLeft;
            while (p->pRight != nullptr && p->pRight != current) {
                p = p->pRight;
            }

            if (p->pRight == nullptr) {
                p->pRight = current;
                current = current->pLeft;
            }
            else {
                p->pRight = nullptr;
                sum += current->key;
                current = current->pRight;
            }
        }
    }

    return sum;
}

int main() {
    TREE T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);
    cout << SumNode(T);
    return 0;
}

