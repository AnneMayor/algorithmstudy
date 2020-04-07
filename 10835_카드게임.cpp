#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int MAX = 2005;

int d[MAX][MAX];
int leftCard[MAX];
int rightCard[MAX];

int recursiveDp(int leftIdx, int rightIdx, int n) {
    if(leftIdx >= n || rightIdx >= n) return 0;

    if(d[leftIdx][rightIdx] != -1) return d[leftIdx][rightIdx];

    d[leftIdx][rightIdx] = max(recursiveDp(leftIdx+1, rightIdx, n), recursiveDp(leftIdx+1, rightIdx+1, n));

    if(leftCard[leftIdx] > rightCard[rightIdx]) {
        d[leftIdx][rightIdx] = max(d[leftIdx][rightIdx] , rightCard[rightIdx] + recursiveDp(leftIdx, rightIdx+1, n));
    }

    return d[leftIdx][rightIdx];
}

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &leftCard[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &rightCard[i]);
    }

    memset(d, -1, sizeof(d));

    printf("%d\n", recursiveDp(0, 0, n));

    return 0;
}