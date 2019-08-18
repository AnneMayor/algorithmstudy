#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 200005;

int start[MAX];
int end1[MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int s, e;
        scanf("%d %d", &s, &e);
        start[i] = s;
        end1[i] = e;
    }

    sort(start, start+n);
    sort(end1, end1+n);
    int ans = 0;

    int idx = 0;
    while(idx < n) {
        for(int i = 0; i < n; i++) {
            if(start[i] < end1[idx]) {
                ans += 1;
            } else {
                idx++;
            }
        }
        break;
    }

    printf("%d\n", ans);

    return 0;
}