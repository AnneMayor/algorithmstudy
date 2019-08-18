#include <iostream>
#include <cstring>

using namespace std;
// const int MAX = 1e8;

// int cnt[MAX];

int n, k;
int cnt;

// 시간초과(O(n^2))

// void findAns(int numOfBottle) {

//     int count = 0;
//     int cntOfOne = 0;
//     int cntOfType = 0;

//     for(int i = 1; i <= numOfBottle; i++) {
//         if(cnt[i] > 0) {
//             cntOfType += 1;
//             count += cnt[i];
//         }
//     }

//     for(int i = 1; i <= numOfBottle; i++) {
//         if(cnt[i] == 1) cntOfOne += 1;
//     }

//     if(count == k) {
//         flag = false;
//         return ;
//     }

//     if(cntOfType == cntOfOne) {
//         return ;
//     }

//     for(int i = 1; i <= numOfBottle; i++) {
//         if(cnt[i] >= 2) {
//             cnt[i] -= 2;
//             cnt[i+i] += 1;
//             findAns(numOfBottle);
//         }
//     }

// }

// int main() {

//     scanf("%d %d", &n, &k);

//     flag = true;
//     int cntOfBottle = 0;

//     // memset(cnt, 0, sizeof(cnt));
//     // cnt[1] = n+cntOfBottle;
//     findAns(n + cntOfBottle);

//     while(flag) {

//         memset(cnt, 0, sizeof(cnt));
//         cnt[1] = n+cntOfBottle;
//         findAns(n + cntOfBottle);

//         if(!flag) break;

//         cntOfBottle += 1;
//     }

//     if(cntOfBottle <= 0) {
//         printf("-1\n");
//     } else {
//         printf("%d\n", cntOfBottle);
//     }

//     return 0;
// }

void getCount(int num) {
    while (num > 0)
    {
        if(num % 2 == 1) cnt++;
        num /= 2;
    }
}

int main() {

    scanf("%d %d", &n, &k);

    int ans = 0;
    while(true) {
        cnt = 0;
        getCount(n+ans);
        if(cnt <= k) break;
        ans++;
    }

    printf("%d\n", ans);

    return 0;
}