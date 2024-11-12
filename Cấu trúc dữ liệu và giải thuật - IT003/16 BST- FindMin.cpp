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

TNODE* FindMin(TREE T){

    while (T->pLeft != nullptr) { // Duyệt về phía trái nhất
        T = T->pLeft;
    }
    return T; // Giá trị nhỏ nhất
}
//Donotedit
int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	if(T==NULL) cout << "Empty Tree.";
	else cout << FindMin(T)->key;
	return 0;
}
