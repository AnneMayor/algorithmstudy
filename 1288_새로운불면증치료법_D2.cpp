#include <iostream>

using namespace std;

bool isChecked[10];

void setFalse() {
    for(int i = 0; i < 10; i++) {
        isChecked[i] = false;
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {

        setFalse();

        int n;
        scanf("%d", &n);

        int cnt = 0;
        int ans = 1;

        int tempN = n;

        while(1) {

            if(cnt >= 10) break;

            if(tempN <= 0) {
                ans += 1;
                tempN = n * ans;
            }

            int num = tempN % 10;
            if(!isChecked[num]) {
                isChecked[num] = true;
                cnt += 1;
            }

            tempN /= 10;

        }

        printf("#%d %d\n", t, ans*n);

    }


    return 0;
}