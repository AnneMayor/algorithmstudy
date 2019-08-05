#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 55;

char str[MAX];
int memory[MAX];

void setMemory(int idx, int n, int val) {
    for(int i = idx; i < n; i++) {
        memory[i] = val;
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        scanf("%s", str);

        int len = strlen(str);
        int ans = 0;
        // 초기화
        for(int i = 0; i < len; i++) {
            memory[i] = 0;
        }

        for(int i = 0; i < len; i++) {
            if(str[i]-'0' == memory[i]) continue;
            setMemory(i, len, str[i]-'0');
            ans += 1;
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}