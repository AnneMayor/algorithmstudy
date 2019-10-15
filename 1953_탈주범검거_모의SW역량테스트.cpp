#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 55;

int map[MAX][MAX];
int isVisited[MAX][MAX];
// 차례대로 상, 하, 좌, 우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Hole
{
    int x, y;
    int step;
    int dir;
    int time;
};

queue<Hole> q;
int n, m, r, c, l;

void moveDir(int nx, int ny, int dir, int step, int time)
{
    Hole h;
    switch (dir)
    {
    // 상
    case 0:
        if (!isVisited[nx][ny] && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 5 || map[nx][ny] == 6))
        {
            isVisited[nx][ny] = time+1;
            h.x = nx;
            h.y = ny;
            h.step = step + 1;
            h.dir = map[nx][ny];
            h.time = time + 1;
            q.push(h);
        }
        break;

    // 하
    case 1:
        if (!isVisited[nx][ny] && (map[nx][ny] == 1 || map[nx][ny] == 2 || map[nx][ny] == 4 || map[nx][ny] == 7))
        {
            isVisited[nx][ny] = time+1;
            h.x = nx;
            h.y = ny;
            h.step = step + 1;
            h.dir = map[nx][ny];
            h.time = time + 1;
            q.push(h);
        }
        break;

    // 좌
    case 2:
        if (!isVisited[nx][ny] && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 4 || map[nx][ny] == 5))
        {
            isVisited[nx][ny] = time+1;
            h.x = nx;
            h.y = ny;
            h.step = step + 1;
            h.dir = map[nx][ny];
            h.time = time + 1;
            q.push(h);
        }
        break;

    // 우
    case 3:
        if (!isVisited[nx][ny] && (map[nx][ny] == 1 || map[nx][ny] == 3 || map[nx][ny] == 6 || map[nx][ny] == 7))
        {
            isVisited[nx][ny] = time+1;
            h.x = nx;
            h.y = ny;
            h.step = step + 1;
            h.dir = map[nx][ny];
            h.time = time + 1;
            q.push(h);
        }
        break;
    }
}

void moveThief(int x, int y, int dir, int step, int time)
{
    switch (dir)
    {
    case 1:
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            moveDir(nx, ny, i, step, time);
        }
        break;

    case 2:
        for (int i = 0; i < 2; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            moveDir(nx, ny, i, step, time);
        }
        break;

    case 3:
        for (int i = 2; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            moveDir(nx, ny, i, step, time);
        }
        break;

    case 4:
        for (int i = 0; i < 4; i++)
        {
            if (i == 0 || i == 3)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                moveDir(nx, ny, i, step, time);
            }
        }
        break;

    case 5:
        for (int i = 0; i < 4; i++)
        {
            if (i == 1 || i == 3)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                moveDir(nx, ny, i, step, time);
            }
        }
        break;

    case 6:
        for (int i = 0; i < 4; i++)
        {
            if (i == 1 || i == 2)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                moveDir(nx, ny, i, step, time);
            }
        }
        break;

    case 7:
        for (int i = 0; i < 4; i++)
        {
            if (i == 0 || i == 2)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                moveDir(nx, ny, i, step, time);
            }
        }
        break;
    }

    return;
}

void bfs(int x, int y, int step, int dir, int time)
{
    Hole h;
    h.x = x;
    h.y = y;
    h.step = step;
    h.dir = dir;
    isVisited[x][y] = time;
    h.time = time;
    q.push(h);

    while (!q.empty())
    {
        x = q.front().x;
        y = q.front().y;
        step = q.front().step;
        dir = q.front().dir;
        time = q.front().time;
        q.pop();

        if(time >= l) return ;

        moveThief(x, y, dir, step, time);
    }

    return;
}

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }

        int ans = 0;
        memset(isVisited, false, sizeof(isVisited));

        bfs(r, c, 1, map[r][c], 1);

        while (!q.empty())
        {
            q.pop();
        }
        
        // cout << "--------------------------------------" << endl;
        // for(int i = 0 ; i < n; i++) {
        //     for(int j = 0; j < m; j++) {
        //         cout << isVisited[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(isVisited[i][j] > 0 && isVisited[i][j] <= l) ans++;
            }
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}