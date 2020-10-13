#include <iostream>

using namespace std;

int main(void) {

    char s, t;
    scanf("%c %c", &s, &t);

    if(s == 'Y') {
        t -= 'a';
        t += 'A';
        printf("%c\n", t);
    } else {
        printf("%c\n", t);
    }

    return 0;
}