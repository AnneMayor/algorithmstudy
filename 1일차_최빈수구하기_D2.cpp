#include <iostream>

using namespace std;

const int MAX = 1005;
int check[MAX];

void setDefault() {
    for(int i = 0; i < MAX; i++) {
        check[i] = 0;
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int i = 0; i < T; i++) {
        int t;
        scanf("%d", &t);

        setDefault();

        for(int i = 0; i < 1000; i++) {
            int score;
            scanf("%d", &score);
            check[score] += 1;
        }

        int ans = 0;
        int idx = 0;

        for(int i = 0; i < MAX; i++) {
            if(idx <= check[i]) {
                idx = check[i];
                ans = i;
            }
        }

        printf("#%d %d\n", t, ans);

    }

    return 0;
}