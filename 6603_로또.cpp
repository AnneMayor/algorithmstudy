#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 60;

bool isChecked[MAX];
vector<int> numList;
int lotteryNum[MAX];

void printAns() {
    for(int i = 0; i < (int) numList.size(); i++) {
        printf("%d ", numList[i]);
    }
    printf("\n");
}

void combination(int idx, int cnt, int k) {
    if(cnt >= 6) {
        printAns();
        return ;
    }

    for(int i = idx; i < k; i++) {
        numList.push_back(lotteryNum[i]);
        combination(i+1, cnt+1, k);
        numList.pop_back();
    }

    return ;
}

int main() {

    while (1)
    {
        numList.clear();

        int k;
        scanf("%d", &k);
        if(k == 0) break;
        for(int i = 0; i < k; i++) {
            scanf("%d", &lotteryNum[i]);
        }

        combination(0, 0, k);

        printf("\n");
    }

    return 0;
}