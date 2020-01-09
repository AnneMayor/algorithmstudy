#include <iostream>
#include <stack>

using namespace std;

const int MAX = 500005;
long height[MAX];

int main() {

    int N;
    scanf("%d", &N);
    
    long ans = 0;

    stack<pair<long, long> > st; // first: height, second: sequential number

    for(int i = 0; i < N; i++) {
        scanf("%ld", &height[i]);
    }

    for(int i = 0; i < N; i++) {

        while (!st.empty() && st.top().first < height[i])
        {
            ans += st.top().second;
            st.pop();
        }

        if(st.empty()) {
            st.push(make_pair(height[i], 1));
        } else {
            if(st.top().first == height[i]) {
                pair<long, long> curHeight = st.top();
                st.pop();

                ans += curHeight.second;
                
                // 여기가 핵심!!
                if(!st.empty()) ans += 1;

                curHeight.second += 1;
                st.push(curHeight);

            } else {
                st.push(make_pair(height[i], 1));
                ans += 1;
            }
        }
        
    }

    printf("%ld\n", ans);

    return 0;
}