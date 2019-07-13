#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<int> q;

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, idx;
        scanf("%d %d", &n, &idx);

        while (!q.empty())
        {
            q.pop();
        }
        

        int nums[n];
        int order[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &nums[i]);
            order[i] = nums[i];
            q.push(i);
        }

        sort(order, order+n, greater<int>());

        int step = 0;
        int index = 0;

        while (!q.empty())
        {
            int cnt = q.front();

            if(index >= n) break;

            if(nums[cnt] == order[index]) {
                step += 1;
                index += 1;
                q.pop();
                if(cnt == idx) {
                    printf("%d\n", step);
                    break;
                }
            } else {
                q.pop();
                q.push(cnt);
            }
        }
        



    }

}