#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {

    int n;

    while (true)
    {
        scanf("%d", &n);
        if(!n) break;

        stack<pair<int, int> > st;

        long long ans = 0;
        for(int i = 0; i <= n; i++) {
            int i_height;
            if(i < n) scanf("%d", &i_height);
            else i_height = -1;

            int curIdx = i;
            while(!st.empty() && st.top().second > i_height) {
                // ...개충격...이거 주의하자,,,놀랐다,,,
                // long long val = st.top().second*(i-st.top().first);
                // ans = max(ans, val);
                // 주석 코드가 "틀렸습니다"하는 코드임. 위 코드흐름에선 아래처럼 작성해야 원하는 값 나올 수 있음에 유의하기.
                ans = max(ans, ((long long)i - st.top().first)*st.top().second);
                curIdx = st.top().first;
                st.pop();
            }
            st.push(make_pair(curIdx, i_height));
        }

        printf("%lld\n", ans);

    }

    return 0;
}