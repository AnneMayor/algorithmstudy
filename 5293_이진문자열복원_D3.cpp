#include <iostream>
#include <string>
#include <cmath>

using namespace std;
string ans;

void findAns(string numList, int a, int b, int c, int d) {
    if(ans != "") return;
    // 이 조건처리 안해주면 시간초과 에러남.
    if(abs(b-c) > 1) return;
    if(a < 0 || b < 0 || c < 0 || d < 0) return;
    if(a == 0 && b == 0 && c == 0 && d == 0) {
        ans = numList;
        return;
    }

    if(numList.back() == '0') {
        findAns(numList+"0", a-1, b, c, d);
        findAns(numList+"1", a, b-1, c, d);
    } else {
        findAns(numList+"0", a, b, c-1, d);
        findAns(numList+"1", a, b, c, d-1);
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        ans = "";
        string nums = "";
        findAns(nums+"0", a, b, c, d);
        findAns(nums+"1", a, b, c, d);

        if(ans == "") {
            printf("#%d impossible\n", tc);
        } else {
            printf("#%d %s\n", tc, ans.c_str());
        }

    }

    return 0;
}