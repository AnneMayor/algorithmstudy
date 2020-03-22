#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {

        vector<int> houseList;
        int n, b;
        scanf("%d %d", &n, &b);

        for(int i = 0; i < n; i++) {
            int price;
            scanf("%d", &price);
            houseList.push_back(price);
        }

        sort(houseList.begin(), houseList.end());

        int curPrice = 0;
        int cntOfBought = 0;
        for(int i = 0; i < n; i++) {
            curPrice += houseList[i];
            if(curPrice <= b) {
                cntOfBought++;
            } else break;
        }

        printf("Case #%d: %d\n", tc, cntOfBought);
        
    }


    return 0;
}