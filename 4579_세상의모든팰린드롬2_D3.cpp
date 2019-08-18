#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 25;

char str[MAX];

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        scanf("%s", str);

        int s = 0;
        int e = strlen(str)-1;

        bool flag = true;
        while(s <= e) {
            if((str[e] == '*') && (str[s] == '*')) break;
            else if(str[s] == '*') {
                for(; str[e] != '*'; e--);
                s++;
            } else if(str[e] == '*') {
                for(; str[s] != '*'; s++);
                e--;
            } else if(str[s] == str[e]) {
                s++;
                e--;
            } else {
                flag = false;
                break;
            }
        }

        if(flag) {
            printf("#%d Exist\n", tc);
        } else {
            printf("#%d Not exist\n", tc);
        }
    }

    return 0;
}