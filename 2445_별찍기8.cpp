#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    // 위 ~ 가운데
    for(int i = 1; i <= n; i++) {
        
        for(int x = 1; x <= i; x++) {
            printf("*");
        }

        for (int x = 1; x <= n-i; x++) {
            printf(" ");
        }

        for (int x = 1; x <= n-i; x++) {
            printf(" ");
        }

        for(int x = 1; x <= i; x++) {
            printf("*");
        }

        printf("\n");

    }

    // 아래
    for(int i = 1; i < n; i++) {
        
        for(int x = 1; x <= n-i; x++) {
            printf("*");
        }

        for(int x = 1; x <= i; x++) {
            printf(" ");
        }

        for(int x = 1; x <= i; x++) {
            printf(" ");
        }

        for(int x = 1; x <= n-i; x++) {
            printf("*");
        }

        printf("\n");

    }

    return 0;
}