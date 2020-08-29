#include <bits/stdc++.h>
#include <random>

using namespace std;

bool isOk(pair<int, int> p, pair<int, int> q) {
    if(p.first==q.first) return false;
    if(p.second==q.second) return false;
    if(p.first+p.second==q.first+q.second) return false;
    if(p.first-p.second==q.first-q.second) return false;
    return true;
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int r, c;
        scanf("%d %d", &r, &c);

        vector<pair<int, int> > order;
        mt19937 mt(3333);
        for(int _ = 0; _ < 100; _++) {
            vector<pair<int, int> > space;  
            for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                    space.push_back(make_pair(i, j));
                }
            }

            bool isVisited[r*c+5];
            memset(isVisited, false, sizeof(isVisited));

            shuffle(space.begin(), space.end(), mt);
            int z = 0;
            vector<pair<int, int> > visited;
            visited.push_back(space[0]);
            isVisited[z] = true;
            z = (z+1) % space.size();
            while (visited.size() < space.size())
            {
                pair<int, int> cur = visited.back();
                if(cur == space[z]) break;
                if(!isVisited[z] && isOk(cur, space[z])) {
                    isVisited[z] = true;
                    visited.push_back(space[z]);
                }
                z = (z+1) % space.size();
            }
            if(visited.size() == space.size()) {
                for(auto s : visited)
                    order.push_back(s);
                break;
            }
        }

        printf("Case #%d: ", tc);
        if(order.empty()) printf("IMPOSSIBLE\n");
        else {
            printf("POSSIBLE\n");
            for(auto ans : order) {
                printf("%d %d\n", (ans.first+1), (ans.second+1));
            }
        }
    }

    return 0;
}