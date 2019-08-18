#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++) {
        int n;
        scanf("%d", &n);

        char alph[n];
        int nums[n];

        for(int i = 0; i < n; i++) {
            scanf("%c", &alph[i]);
            // 입력 버퍼에 'Enter' 버퍼가 남아있으므로 입력이 제대로 되지 않아 다음과 같이 처리해줌.
            // fflush(stdin);
            scanf("%c",&alph[i]);
            scanf("%d", &nums[i]);
        }

        int cnt = 0;
        printf("#%d\n", t);
        for(int i = 0; i < n; i++) {
            while(nums[i] > 0) {
                if(cnt >= 10) {
                    cnt = 0;
                    printf("\n");
                }
                cnt++;
                printf("%c", alph[i]);
                nums[i]--;
            }

        }
        
        printf("\n");

    }
    return 0;
}