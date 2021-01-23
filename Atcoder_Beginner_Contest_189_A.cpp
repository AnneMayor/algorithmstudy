#include <bits/stdc++.h>

using namespace std;

int main(void) {

    char letters[3];
    scanf("%s", letters);

    for(int i = 0; i < 2; i++) {
        if(letters[i] != letters[i+1]) {
            printf("Lost\n");
            return 0;
        }
    }

    printf("Won\n");

    return 0;
}