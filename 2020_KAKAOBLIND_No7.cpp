#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

#define HOR 0
#define VER 1

using namespace std;
const int MAX = 105;

int timeOfMoving;
// 0: left , 1: right, 2: up, 3: down
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct Robot
{
    int x1, y1;
    int x2, y2;
    int type;
};

queue<Robot> q;
int d[MAX][MAX][MAX][MAX];

void moveRobot(int x1, int y1, int x2, int y2, int n, vector<vector<int>> board)
{

    Robot rb;
    rb.x1 = x1;
    rb.y1 = y1;
    rb.x2 = x2;
    rb.y2 = y2;
    d[x1][y1][x2][y2] = 0;
    rb.type = HOR;
    q.push(rb);

    while (!q.empty())
    {
        rb = q.front();
        q.pop();
        x1 = rb.x1;
        y1 = rb.y1;
        x2 = rb.x2;
        y2 = rb.y2;
        int timeOfMoved = d[x1][y1][x2][y2];
        int type = rb.type;

        if (((x1 == n - 1) && (y1 == n - 1)) || ((x2 == n - 1) && (y2 == n - 1)))
        {
            timeOfMoving = timeOfMoved;
            return;
        }

        // cout << "x1: " << x1 << " / y1: " << y1 << " x2: " << x2 << " / y2: " << y2 << endl;
        // cout << "timeOfMoved: " << timeOfMoved << endl;

        // 상하좌우 이동
        for (int i = 0; i < 4; i++)
        {
            int nX1 = x1 + dx[i];
            int nY1 = y1 + dy[i];
            int nX2 = x2 + dx[i];
            int nY2 = y2 + dy[i];

            if (nX1 < 0 || nY1 < 0 || nX1 >= n || nY1 >= n || nX2 < 0 || nY2 < 0 || nX2 >= n || nY2 >= n)
                continue;

            if (board[nX1][nY1] == 1 || board[nX2][nY2] == 1)
                continue;

            if (d[nX1][nY1][nX2][nY2] == -1)
            {
                d[nX1][nY1][nX2][nY2] = timeOfMoved + 1;
                rb.x1 = nX1;
                rb.y1 = nY1;
                rb.x2 = nX2;
                rb.y2 = nY2;
                q.push(rb);
            }

            // 회전
            if (type == HOR && i == 2)
            {
                // up
                if (d[x1-1][y1][x1][y1] == -1)
                {
                    d[x1-1][y1][x1][y1] = timeOfMoved + 1;
                    q.push({x1-1, y1, x1, y1, 1 - type});
                }
                if (d[x2-1][y2][x2][y2] == -1)
                {
                    d[x2-1][y2][x2][y2] = timeOfMoved + 1;
                    q.push({x2-1, y2, x2, y2, 1 - type});
                }
            }
            else if (type == HOR && i == 3)
            {
                // down
                if (d[x1][y1][x1 + 1][y1] == -1)
                {
                    d[x1][y1][x1 + 1][y1] = timeOfMoved + 1;
                    q.push({x1, y1, x1 + 1, y1, 1 - type});
                }
                if (d[x2][y2][x2 + 1][y2] == -1)
                {
                    d[x2][y2][x2 + 1][y2] = timeOfMoved + 1;
                    q.push({x2, y2, x2 + 1, y2, 1 - type});
                }
            }
            else if (type == VER && i == 0)
            {
                // left
                if (d[x1][y1-1][x1][y1] == -1)
                {
                    d[x1][y1-1][x1][y1] = timeOfMoved + 1;
                    q.push({x1, y1-1, x1, y1, 1 - type});
                }
                if (d[x2][y2-1][x2][y2] == -1)
                {
                    d[x2][y2-1][x2][y2] = timeOfMoved + 1;
                    q.push({x2, y2-1, x2, y2, 1 - type});
                }
            }
            else if (type == VER && i == 1)
            {
                // right
                if (d[x1][y1][x1][y1+1] == -1)
                {
                    d[x1][y1][x1][y1+1] = timeOfMoved + 1;
                    q.push({x1, y1, x1, y1+1, 1 - type});
                }
                if(d[x2][y2][x2][y2+1] == -1) {
                    d[x2][y2][x2][y2+1] = timeOfMoved + 1;
                    q.push({x2, y2, x2, y2+1, 1-type});
                }
            }
        }
    }

    return;
}

int solution(vector<vector<int>> board)
{

    timeOfMoving = 0;
    int n = board.size();
    memset(d, -1, sizeof(d));

    moveRobot(0, 0, 0, 1, n, board);

    return timeOfMoving;
}