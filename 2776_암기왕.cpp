#include <iostream>
#include <algorithm>

using namespace std;
bool flag;

void binarySearch(int nums1[], int num, int start, int end) {

    if(start > end) {
        return;
    }

    int mid = (start+end) / 2;

    if(nums1[mid] == num)  {
        flag = true;
    } else {
        if(nums1[mid] > num) {
            binarySearch(nums1, num, start, mid-1);
        } else {
            binarySearch(nums1, num, mid+1, end);
        }
    }

}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        
        int n;
        scanf("%d", &n);

        int nums1[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &nums1[i]);
        }

        sort(nums1, nums1+n);

        int m;
        scanf("%d", &m);

        int nums2[m];
        for(int i = 0; i < m; i++) {
            scanf("%d", &nums2[i]);
        }

        for(int i = 0; i < m; i++) {
            flag = false;
            binarySearch(nums1, nums2[i], 0, n-1);
            if(flag) printf("1\n");
            else printf("0\n");
        }


    }
    

    return 0;
}