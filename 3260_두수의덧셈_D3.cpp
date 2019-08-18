#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
const int MAX = 105;

char a[MAX];
char b[MAX];
int ans[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        scanf("%s %s", a, b);

        int lenA = strlen(a);
        int lenB = strlen(b);

        if(lenA == lenB) {

            int tmpA = lenA-1;
            int tmpB = lenB-1;

            int ansIdx = lenA-1;
            int remain = 0;
            while (tmpA >= 0 && tmpB >= 0)
            {
                int tmp = (a[tmpA]-'0') + (b[tmpB]-'0')+remain;
                if(tmpA == 0 && tmpB == 0) {
                    ans[ansIdx--] = tmp;
                } else {
                    ans[ansIdx--] = tmp%10;
                }
                remain = tmp/10;
                
                tmpA--;
                tmpB--;
            }
            
        } else {

            int tmpA = lenA-1;
            int tmpB = lenB-1;

            int ansIdx = max(lenA, lenB)-1;
            int remain = 0;
            while (tmpA >= 0 && tmpB >= 0)
            {
                int tmp = (a[tmpA]-'0') + (b[tmpB]-'0')+remain;
                if(tmpA == 0 && tmpB == 0) {
                    ans[ansIdx--] = tmp;
                } else {
                    ans[ansIdx--] = tmp%10;
                }
                remain = tmp/10;
                
                tmpA--;
                tmpB--;
            }

            if(tmpA < 0) {
                for(int i = tmpB; i >= 0; i--) {
                    int tmp = (b[i]-'0')+remain;
                    if(i == 0) {
                        ans[i] = tmp;
                    } else {
                        ans[i] = tmp%10;
                    }
                    remain = tmp/10;
                }
            } else {
                for(int i = tmpA; i >= 0; i--) {
                    int tmp = (a[i]-'0')+remain;
                    if(i == 0) {
                        ans[i] = tmp;
                    } else {
                        ans[i] = tmp%10;
                    }
                    remain = tmp/10;
                }
            }
        }

        printf("#%d ", tc);
        int len = max(lenA, lenB);
        for(int i = 0; i < len; i++) {
            printf("%d", ans[i]);
        }
        printf("\n");
    }



    return 0;
}