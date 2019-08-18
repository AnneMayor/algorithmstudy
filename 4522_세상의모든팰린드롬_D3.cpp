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

        int start = 0;
        int end = strlen(str)-1;

        bool flag = true;

        while(start < end) {
            
            if(str[start] == str[end] || str[start] == '?' || str[end] == '?') {
                start += 1;
                end -= 1;
            } else if(str[end] != '?' && str[start] != '?' && str[start] != str[end]) {
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