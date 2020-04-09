#include <iostream>

using namespace std;
const int MAX = 1e5+3;

int ans;

void recursive(int num) {

    if(num==1) return ;
    
    if(ans < num) ans = num;
    
    if(num%2) {
        recursive(num*3+1);
    } else {
        recursive(num/2);
    }

    return ;
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);
        ans = n;
        recursive(n);
        printf("%d\n", ans);
    }

    return 0;
}