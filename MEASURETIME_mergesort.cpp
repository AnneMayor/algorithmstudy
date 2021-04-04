#include <bits/stdc++.h>

using namespace std;

long long mergeSort(vector<int> & nums, int left, int right) {

    if(left == right) return 0;

    int mid = (left + right) / 2;
    long long ret = mergeSort(nums, left, mid) + mergeSort(nums, mid+1, right);

    vector<int> temp(right-left+1);

    int tempIdx = 0, leftIdx = left, rightIdx = mid+1;
    while (leftIdx <= mid || rightIdx <= right)
    {
        if(leftIdx <= mid && (rightIdx > right || nums[leftIdx] <= nums[rightIdx])) {
            temp[tempIdx++] = nums[leftIdx++];
        } else {
            ret += mid - leftIdx + 1;
            temp[tempIdx++] = nums[rightIdx++];
        }
    }

    for(int i = 0; i < temp.size(); i++) {
        nums[left+i] = temp[i];
    }

    return ret;    
}

int main(void) {

    int T;
    scanf("%d", &T);

    vector<int> nums;

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d",&n);

        nums.clear();    
        long long result = 0;
        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            nums.push_back(num);
        }

        result = mergeSort(nums, 0, n-1);

        printf("%lld\n", result);
    }

    return 0;
}