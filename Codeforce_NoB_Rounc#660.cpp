#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        int cntOfNum8 = ceil((n%4 != 0? n/4+1 : n/4));
        for(int i = 0; i < n-cntOfNum8; i++) {
            printf("9");
        }
        for(int i = 0; i < cntOfNum8; i++) {
            printf("8");
        }

        printf("\n");
    } 


    return 0;
}