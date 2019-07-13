#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n;
        scanf("%d", &n);

        stack<pair<int, int> > st;

        int ans = 0;
        for(int i = 0; i <= n; i++) {
            int i_height;
            if(i < n) scanf("%d", &i_height);
            else i_height = -1;

            int curIdx = i;
            while (!st.empty() && st.top().second > i_height)
            {
                ans = max(ans, st.top().second * (i-st.top().first));
                curIdx = st.top().first;
                st.pop();
            }
            st.push(make_pair(curIdx, i_height));
            
        }

        printf("%d\n", ans);
    }

    return 0;
}