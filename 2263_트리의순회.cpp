#include <iostream>

using namespace std;
const int MAX = 100005;

int inOrder[MAX];
int postOrder[MAX];
int idx[MAX];

int n;

void findPreOrder(int inStart, int inEnd, int postStart, int postEnd) {
    
    if(inStart > inEnd || postStart > postEnd) return;

    int root = postOrder[postEnd];
    printf("%d ", root);
    int left = idx[root] - inStart;
    // 왼쪽
    findPreOrder(inStart, idx[root]-1, postStart, postStart+left-1);
    // 오른쪽
    findPreOrder(idx[root]+1, inEnd, postStart+left, postEnd-1);
}

int main() {

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &inOrder[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &postOrder[i]);
    }

    for(int i = 0; i < n; i++) {
        idx[inOrder[i]] = i;
    }

    findPreOrder(0, n-1, 0, n-1);
    printf("\n");

    return 0;
}