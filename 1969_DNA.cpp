#include <iostream>
#include <set>
#include <vector>
#include <cmath>


using namespace std;
const int MAX = 10005;

char str[MAX][MAX];
vector<char> s;
multiset<char> ms;

int main() {

    int n,m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    s.clear();

    // 문자열 구하기
    for(int i = 0; i < m; i++) {

        ms.clear();
        for(int j = 0; j < n; j++) {
            ms.insert(str[j][i]);
        }

        int ans = -1000;
        int cnt = ms.count('T');
        ans = max(ans, cnt);
        cnt = ms.count('A');
        ans = max(ans, cnt);
        cnt = ms.count('G');
        ans = max(ans, cnt);
        cnt = ms.count('C');
        ans = max(ans, cnt);

        cnt = 0;
        cnt = ms.count('T');

        s.push_back('T');
        if(cnt == ans) {
            s.pop_back();
            s.push_back('T');
        }

        cnt = ms.count('G');
        if(cnt == ans) {
            s.pop_back();
            s.push_back('G');
        }

        cnt = ms.count('C');
        if(cnt == ans) {
            s.pop_back();
            s.push_back('C');
        }

        cnt = ms.count('A');
        if(cnt == ans) {
            s.pop_back();
            s.push_back('A');
        }
        
    }

    for(int i = 0; i < m; i++) {
        printf("%c", s[i]);
    }
    printf("\n");

    // Hamming Distance 구하기

    int cntOfAns = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i] != str[j][i]) {
                cntOfAns += 1;
            }
        }
    }

    printf("%d\n", cntOfAns);

    return 0;
}