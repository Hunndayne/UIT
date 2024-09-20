/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
for
while
goto
###End banned keyword*/

#include <iostream>
using namespace std;
#define MAXN 400000

void NhapMang(int A[], const int N) {
    for (int i = 0; i < N; i++)
        std::cin >> A[i];
}

int binary_search_recursive(int a[], int n, int low, int high, int x) {
    if (high<low) return -1;
    int mid = low + (high - low) / 2;
    if (a[mid] == x) return 1;
    if (a[mid] < x) return binary_search_recursive(a, n, mid + 1, high, x);
    else return binary_search_recursive(a, n, low, mid - 1, x);
}

int binary_search(int a[], int n, int x) {

    int low = 0;
    int high = n - 1;
    return binary_search_recursive(a, n, low, high, x);

}

//###INSERT CODE HERE -

int main() {
    int x, n, a[MAXN];

    cin >> x;
    cin >> n;
    NhapMang(a, n);


    int i = binary_search(a, n, x);

    if (i == -1) std::cout << "false";
    else std::cout << "true";

    return 0;
}

