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


void CreateEmptyTree(TREE& T) {
	T = NULL;
}
TNODE* CreateTNode(int x) {
	TNODE* p = new TNODE; //cấp phát vùng nhớ động
	p->key = x; //gán trường dữ liệu của node = x
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
int Insert(TREE& T, TNODE* p) {
	if (T) {
		if (T->key == p->key) return 0;
		if (T->key > p->key)
			return Insert(T->pLeft, p);
		return Insert(T->pRight, p);
	}
	T = p;
	return 1;
}
//###INSERT CODE HERE -
void CreateTree(TREE& T) {
	CreateEmptyTree(T);
	int value;


	while (cin >> value && value != -1) {
		TNODE* p = CreateTNode(value); 
		Insert(T, p); 
	}
}
void FindParent(TREE T, int x) {
	if (T == nullptr) {
		cout << "Empty Tree." << endl;
		return;
	}
	TNODE* Parent = nullptr;
	TNODE* Current = T;

	while (Current) {
		if (Current->key == x) {
			if (Parent == nullptr) {
				cout << x << " has no parent." << endl;
			}
			else {
				cout << Parent->key << " is parent of " << x << "." << endl;
			}
			return;
		}
		Parent = Current;
		if (Current->key < x) {
			Current = Current->pRight;
		}
		else {
			Current = Current->pLeft;
		}
	}
	cout << "Not found " << x <<"." << endl;
}

int main() {
	TREE T; //hay: TNODE* T;
	T = NULL; // Khoi tao cay T rong, or: CreateEmptyTree(T)
	CreateTree(T);

	int x;
	cin >> x;

	FindParent(T, x);

	return 0;
}
