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
TNODE* searchNode(TREE T, int x) {
    if (T == nullptr) 
        return nullptr;
    if (T->key == x) 
        return T;
    if (T->key>x) 
        return(searchNode(T->pLeft, x));
    if (T->key) 
        return(searchNode(T->pRight, x));
}

// Do not edit main
int main() {
    TREE T; //hay: TNODE* T;
    T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
    CreateTree(T);

    int x;
    cin >> x;
    if (searchNode(T, x)) cout << "true";
    else cout << "false";
    return 0;
}
