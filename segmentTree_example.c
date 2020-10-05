#include <stdio.h>
#include <string.h>

const int MAX = 20;

int tree[MAX];
int num[] = {1, -8, 2, 19, 102, -1, 2, 123, -123, 192, -200};

int init(int start, int end, int node) {
    if(start == end) return tree[node] = num[start];
    int mid = (start+end) / 2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

int sum(int start, int end, int node, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void update(int start, int end, int node, int index, int diff) {
    if(index < start || index > end) return ;
    tree[node] += diff;
    if(start == end) return ;
    int mid = (start+end) / 2;
    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);

}

int main(void) {

    memset(tree, 0, sizeof(tree));

    // 구간합 트리 그리기
    init(0, 10, 1);
    printf("0~10까지의 합: %d\n", sum(0, 10, 1, 0, 10));
    update(0, 10, 1, 4, 3);
    printf("update 후 0~10까지의 합: %d\n", sum(0, 10, 1, 0, 10));

    return 0;
}