#include <bits/stdc++.h>

using namespace std;
const int MAX = 105;

vector<vector<int> > familyRelationship(MAX);
queue<pair<int, int> > q;
int ans;
bool isChecked[MAX];

void bfs(int start, int end) {

    int cnt = 0;
    isChecked[start] = true;
    q.push(make_pair(start, cnt));
    
    while (!q.empty())
    {
        start = q.front().first;
        cnt = q.front().second;
        q.pop();

        isChecked[start] = true;

        if(start == end) {
            ans = cnt;
            return ;
        }

        for(int i = 0; i < familyRelationship[start].size(); i++) {
            if(!isChecked[familyRelationship[start][i]]) {
                q.push(make_pair(familyRelationship[start][i], cnt+1));
            }
        }
    }
    

    return ;
}

int main() {

    int n;
    scanf("%d", &n);

    int a, b;
    scanf("%d %d", &a, &b);

    int m;
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int p1, p2;
        scanf("%d %d", &p1, &p2);

        familyRelationship[p1].push_back(p2);
        familyRelationship[p2].push_back(p1);
    }

    ans = -1;
    memset(isChecked, false, sizeof(isChecked));

    bfs(a, b);

    printf("%d\n", ans);
    
    return 0;
}