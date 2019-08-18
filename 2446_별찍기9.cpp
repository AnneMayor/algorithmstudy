#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        for(int x = 1; x <= i; x++) {
            printf(" ");
        }

        for(int x = 1; x <= 2*(n-i)-1; x++) {
            printf("*");
        }

        printf("\n");

    }

    for(int i = 1; i < n; i++) {
        for(int x = 1; x < n-i; x++) {
            printf(" ");
        }

        for(int x = 1; x <= 2*i+1; x++) {
            printf("*");
        }
        
        printf("\n");

    }

    return 0;
}