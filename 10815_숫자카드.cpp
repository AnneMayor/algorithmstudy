#include <iostream>
#include <algorithm>

using namespace std;

bool flag = false;

void binarySearch(int n, int data[], int start, int end) {

    if(data[start] == n) {
        flag = true;
        return;
    }

    if(data[end] == n) {
        flag = true;
        return;
    }

    if(start >= end) {
        flag = false;
        return;
    }

    int mid = (start+end) / 2;

    if(data[mid] == n) {
        flag = true;
        return;
    }

    if(data[mid] > n) {
        binarySearch(n, data, start, mid-1);
    } else {
        binarySearch(n, data, mid+1, end);
    }
    
}

int main() {

    int n, m;
    scanf("%d", &n);
    int data[n+1];
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    scanf("%d", &m);
    int nums[m+1];
    for(int i = 0; i < m; i++) {
        scanf("%d", &nums[i]);
    }

    sort(data, data+n);

    for(int i = 0; i < m; i++) {
        binarySearch(nums[i], data, 0, n-1);
        if(flag) {
            printf("%d ", 1);
        } else {
            printf("%d ", 0);
        }
    }

    return 0;
}