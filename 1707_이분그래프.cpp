#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 2e4 + 5;

int isVisited[MAX];
bool ansFlag;
vector<int> pointList;
vector<vector<int> > points;
queue<int> q;

void bfs(int start)
{
    isVisited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        start = q.front();
        q.pop();

        for (int next : points[start])
        {
            if (!isVisited[next])
            {
                if (isVisited[start] == 1)
                {
                    isVisited[next] = 2;
                }
                else
                {
                    isVisited[next] = 1;
                }
                q.push(next);
            }
            else if (isVisited[start] == isVisited[next])
            {
                ansFlag = false;
                return;
            }
        }
    }

    return;
}

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        ansFlag = true;
        int v, e;
        scanf("%d %d", &v, &e);
        memset(isVisited, 0, sizeof(isVisited));

        points.clear();
        while (!q.empty())
        {
            q.pop();
        }
        points.resize(v + 1);

        for (int i = 0; i < e; i++)
        {
            int s, e;
            scanf("%d %d", &s, &e);
            pointList.push_back(s);
            pointList.push_back(e);
            points[s].push_back(e);
            points[e].push_back(s);
        }

        pointList.erase(unique(pointList.begin(), pointList.end()), pointList.end());

        for(int p : pointList) {
            if(!isVisited[p]) {
                bfs(p);

                if(!ansFlag) break;
            }
        }

        if (ansFlag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}