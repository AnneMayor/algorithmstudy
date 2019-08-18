#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);


    for(int i = 1; i <= n; i++) {
        
        for(int x = 1; x <= n-i; x++) {
            printf(" ");
        }

        for(int x = 1; x <= i; x++) {
            printf("*");
            if(x == i) continue;
            printf(" ");
        }

        printf("\n");
    }

    return 0;
}