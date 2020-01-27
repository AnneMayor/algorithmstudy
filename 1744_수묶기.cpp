#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10001;

vector<int> numList;

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        numList.push_back(val);
    }

    sort(numList.begin(), numList.end(), greater<int>());

    long long ret = 0;

    // 1을 기준으로 양수, 음수 곱셈 나누기
    int left = 0;
    int right = n-1;

    for(; left < right; left+=2) {
        if(numList[left] > 1 && numList[left+1] > 1) {
            ret += numList[left] * numList[left+1];
        } else break;
    }

    for(; right > 0; right-=2) {
        if(numList[right] < 1 && numList[right-1] < 1) {
            ret += numList[right] * numList[right-1];
        } else break;
    }

    for(; left <= right; left++) {
        ret += numList[left];
    }

    printf("%lld\n", ret);
    return 0;
}