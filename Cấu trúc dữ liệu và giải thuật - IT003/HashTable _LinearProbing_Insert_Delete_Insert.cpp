#include <iostream>
#include <string>

using namespace std;

#define LOAD 0.7
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1

struct NODE {
    int flag; // Lưu trạng thái của NODE: -1:DELETE, 0:EMPTY, Giá trị khác: Node đang tồn tại giá trị
    int key;
};

struct HASHTABLE {
    int M; // Kich thuoc bang bam
    int n; // so phan tu hien tai trong bang bam
    NODE* table;
};

int HF(HASHTABLE ht, int key) { return key % ht.M; }

int HF_LinearProbing(HASHTABLE ht, int key, int i) {
    int h = HF(ht, key);
    return (h + i) % ht.M;
}

bool Insert(HASHTABLE& ht, int key) {
    if (float(ht.n + 1) / ht.M > LOAD) {
        return false;
}

    int firstDeletedIndex = -1;
    for (int i = 0; i < ht.M; i++) {
        int index = HF_LinearProbing(ht, key, i);
        
        if (ht.table[index].flag == EMPTY) {
            if (firstDeletedIndex != -1) {
                ht.table[firstDeletedIndex].key = key;
                ht.table[firstDeletedIndex].flag = OCCUPIED;
            } else {

                ht.table[index].key = key;
                ht.table[index].flag = OCCUPIED;
            }
            ht.n++;
            return true;
        }
        
        if (ht.table[index].flag == DELETED && firstDeletedIndex == -1) {
            firstDeletedIndex = index;
        }
        
        if (ht.table[index].flag == OCCUPIED && ht.table[index].key == key) {
            return false;
        }
    }

    if (firstDeletedIndex != -1) {
        ht.table[firstDeletedIndex].key = key;
        ht.table[firstDeletedIndex].flag = OCCUPIED;
        ht.n++;
        return true;
    }

    return false;
}

void Delete(HASHTABLE& ht, int key) {
    int i = 0;
    while (i < ht.M) {
        int index = HF_LinearProbing(ht, key, i);
        if (ht.table[index].flag == EMPTY) {
            return; // Key not found
        }
        if (ht.table[index].flag == OCCUPIED && ht.table[index].key == key) {
            ht.table[index].flag = DELETED;
            ht.table[index].key = 0;
            ht.n--;
            return;
        }
        i++;
    }
}

void CreateHashTable(HASHTABLE& ht) {
    int num;
    cin >> ht.M >> num;
    ht.n = 0;
    ht.table = new NODE[ht.M];
    for (int i = 0; i < ht.M; i++) {
        ht.table[i].flag = EMPTY;
        ht.table[i].key = 0;
    }

    for (int i = 0; i < num; i++) {
        int operation, key;
        cin >> operation >> key;
        if (operation == 1) {
            Insert(ht, key);
        } else if (operation == 0) {
            Delete(ht, key);
        }
    }
}

void Traverse(HASHTABLE H) {
    for (int i = 0; i < H.M; i++) {
        if (H.table[i].flag == OCCUPIED) {
            cout << i << " --> " << H.table[i].key << endl;
        } else if (H.table[i].flag == DELETED) {
            cout << i << " --> DELETED" << endl;
        } else {
            cout << i << " --> EMPTY" << endl;
        }
    }
}

void DeleteHashtable(HASHTABLE& ht) {
    delete[] ht.table;
    ht.table = nullptr;
    ht.M = 0;
    ht.n = 0;
}

int main() {
    HASHTABLE H;
    CreateHashTable(H);
    Traverse(H);
    DeleteHashtable(H);
    return 0;
}
