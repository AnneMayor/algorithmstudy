#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> numList;
vector<int> oddIdxNum;
vector<int> evenIdxNum;
vector<int> totalNum;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        numList.clear();
        oddIdxNum.clear();
        evenIdxNum.clear();
        totalNum.clear();
        int len;
        scanf("%d", &len);
        for(int i = 0; i < len; i++) {
            int num;
            scanf("%d", &num);
            if(i%2) {
                evenIdxNum.push_back(num);
            } else {
                oddIdxNum.push_back(num);
            }
        }

        sort(oddIdxNum.begin(), oddIdxNum.end());
        sort(evenIdxNum.begin(), evenIdxNum.end());

        for(int i = 0; i < len/2; i++) {
            totalNum.push_back(oddIdxNum[i]);
            totalNum.push_back(evenIdxNum[i]);
        }
        if(len%2) totalNum.push_back(oddIdxNum[len/2]);

        int ans = -1;
        for(int i = 0; i < len-1; i++) {
            if(totalNum[i] > totalNum[i+1]) {
                ans = i;
                break;
            }
        }

        if(ans == -1) {
            printf("Case #%d: OK\n", tc);
        } else {
            printf("Case #%d: %d\n", tc, ans);
        }
    }

    return 0;
}