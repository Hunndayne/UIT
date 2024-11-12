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





void inorder(TREE Root) {
    if (Root != nullptr) {
        inorder(Root->pLeft);
        cout << Root->key << " ";
        inorder(Root->pRight);
    }
}

//void PrintTree(TREE T) {
//    if (T == nullptr) {
//        cout << "Empty Tree." << endl;
//    }
//    else {
//        inorder(T);
//        cout << endl;
//    }
//}

void PrintTree(TREE root) {
    if (root == nullptr) {
        cout << "Empty Tree.";
        return;
    }
    inorder(root);
}


int main() {
    TREE T; 
    T = nullptr; 
    CreateTree(T);
    PrintTree(T);
    return 0;
}
