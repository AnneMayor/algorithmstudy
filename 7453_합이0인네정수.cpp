#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 4005;

int nums[MAX][4];

vector<int> firstArr;
vector<int> secondArr;

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d", &nums[i][j]);
        }
    }

    // 첫번째&두번째 열의 합
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            firstArr.push_back(nums[i][0] + nums[j][1]);
        }
    }

    // 세번째&네번째 열의 합
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            secondArr.push_back(nums[i][2] + nums[j][3]);
        }
    }

    sort(firstArr.begin(), firstArr.end());
    sort(secondArr.begin(), secondArr.end());

    int start = 0, end = n*n;
    long long ans = 0;
    for(int firstIdx = start, secondIdx = end-1; (firstIdx < end && secondIdx >= start) ;) {
        long long num = firstArr[firstIdx] + secondArr[secondIdx];
        if(num < 0) {
            firstIdx++;
        } else if(num > 0) {
            secondIdx--;
        } else {
            // 같은 수 있는지 찾기
            int tmpFirst = firstIdx;
            long long cntOfSameFirst = 0, cntOfSameSecond = 0;
            while(firstArr[firstIdx] + secondArr[secondIdx] == 0) {
                if(firstIdx >= end) break;
                cntOfSameFirst++;
                firstIdx++;
            }
            while(firstArr[tmpFirst]+secondArr[secondIdx] == 0) {
                if(secondIdx < start) break;
                cntOfSameSecond++;
                secondIdx--;
            }

            ans += cntOfSameFirst*cntOfSameSecond;
        }
    }
    
    printf("%lld\n", ans);

    return 0;
}