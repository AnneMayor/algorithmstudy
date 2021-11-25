#include <iostream>
#include <string>
#include <cmath>

using namespace std;


int main(void) {

    int n;
    scanf("%d", &n);

    int ans = 0;

    for(int tc = 1; tc <= n; tc++) {
        int num;
        scanf("%d", &num);
        string numArr = to_string(num);

        if(num%2 == 0) {
            ans = 0;
        } else {
            int cntOfEven = 0;
            int idxOfEven = 15;
            for(int i = 0; i < numArr.length(); i++) {
                int digit = numArr[i] - '0';
                if(digit%2 == 0) {
                    cntOfEven++;
                    idxOfEven = min(idxOfEven, i);
                }
            }
            if(cntOfEven == 0) ans = -1;
            else {
                if(idxOfEven <= 0) ans = 1;
                else ans = 2;
            }
        }

        printf("%d\n", ans);
    }

    

    return 0;
}