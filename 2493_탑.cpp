#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

const int MAX = 5e6;
stack<pair<int, int> > st;

int main() {

    int n;
    scanf("%d", &n);

    int result[n];

    int val;
    scanf("%d", &val);

    memset(result, 0, sizeof(result));
    st.push(make_pair(0, val));

    for(int i = 1; i < n; i++) {
        scanf("%d", &val);

        while (!st.empty())
        {
            if(st.top().second <= val) {
                st.pop();
            } else {
                result[i] = st.top().first+1;
                break;
            }
        }

        st.push(make_pair(i, val));
        
    }

    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}