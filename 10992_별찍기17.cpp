#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        if(i == n) {
            for(int x = 1; x <= 2*i-1; x++) {
                printf("*");
            }
        } else {
            for(int x = 1; x <= n-i; x++) {
                printf(" ");
            }

            printf("*");

            for(int x = 1; x <= 2*(i-1) -1; x++) {
                printf(" ");
            }

            if(i != 1) printf("*");

        }

        printf("\n");
    }
    
    return 0;
}