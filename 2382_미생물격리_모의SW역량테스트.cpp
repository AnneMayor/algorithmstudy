#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;
const int MAX = 105;

struct Virus
{
    int cntOfVirus;
    int dir;

    Virus() : cntOfVirus(0), dir(-1) {}
};

Virus virusMap[MAX][MAX];
int cntOfVirusGroup[MAX][MAX];
map<pair<int, int>, vector<Virus> > checkVirus;
int n, m, k;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void moveVirus(int x, int y)
{

    // 방향 이동
    int nx = -1, ny = -1;
    switch (virusMap[x][y].dir)
    {
    // 상
    case 1:
        nx = x + dx[2];
        ny = y + dy[2];
        break;

    // 하
    case 2:
        nx = x + dx[3];
        ny = y + dy[3];
        break;

    // 좌
    case 3:
        nx = x + dx[0];
        ny = y + dy[0];
        break;

    // 우
    case 4:
        nx = x + dx[1];
        ny = y + dy[1];
        break;
    }

    int cntOfVirus = virusMap[x][y].cntOfVirus;
    int dir = virusMap[x][y].dir;

    Virus v;
    v.cntOfVirus = cntOfVirus;
    v.dir = dir;

    if (checkVirus.find(make_pair(nx, ny)) == checkVirus.end())
    {
        vector<Virus> tmp;
        tmp.push_back(v);
        checkVirus.insert(make_pair(make_pair(nx, ny), tmp));
    }
    else
    {
        checkVirus[make_pair(nx, ny)].push_back(v);
    }
    cntOfVirusGroup[nx][ny] += 1;
    cntOfVirusGroup[x][y] -= 1;
    Virus nV;
    virusMap[x][y] = nV;
}

void setVirus(int x, int y)
{
    if (cntOfVirusGroup[x][y] <= 1)
    {
        Virus v;
        v = checkVirus[make_pair(x, y)][0];
        int numOfVirus = v.cntOfVirus;
        int dir = v.dir;
        if (x == 0 || x == n - 1 || y == 0 || y == n - 1)
        {
            numOfVirus /= 2;
            switch (dir)
            {
            case 1:
                dir = 2;
                break;

            case 2:
                dir = 1;
                break;

            case 3:
                dir = 4;
                break;

            case 4:
                dir = 3;
                break;
            }
        }
        
        v.cntOfVirus = numOfVirus;
        v.dir = dir;
        virusMap[x][y] = v;
    }
    else
    {
        int vSize = checkVirus[make_pair(x, y)].size();
        int total = 0;
        int numOfVirus = 0;
        int dir = -1;
        for (int i = 0; i < vSize; i++)
        {
            Virus v = checkVirus[make_pair(x, y)][i];
            total += v.cntOfVirus;
            if (numOfVirus < v.cntOfVirus)
            {
                numOfVirus = v.cntOfVirus;
                dir = v.dir;
            }
        }

        Virus v;
        v.cntOfVirus = total;
        v.dir = dir;
        virusMap[x][y] = v;
    }
}

void initVirusData()
{
    checkVirus.clear();
    memset(cntOfVirusGroup, 0, sizeof(cntOfVirusGroup));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            Virus v = virusMap[x][y];
            if (v.cntOfVirus > 0)
                cntOfVirusGroup[x][y] = 1;
        }
    }
}

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {

        scanf("%d %d %d", &n, &m, &k);
        memset(cntOfVirusGroup, 0, sizeof(cntOfVirusGroup));

        for(int x = 0; x < n; x++) {
            for(int y = 0; y < n; y++) {
                Virus v;
                virusMap[x][y] = v;
            }
        }

        for (int i = 0; i < k; i++)
        {
            int x, y, cntOfVirus, dir;
            scanf("%d %d %d %d", &x, &y, &cntOfVirus, &dir);
            Virus v;
            v.cntOfVirus = cntOfVirus;
            v.dir = dir;
            virusMap[x][y] = v;
            cntOfVirusGroup[x][y] += 1;
        }

        for (int i = 0; i < m; i++)
        {
            initVirusData();
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    int flag = virusMap[x][y].cntOfVirus;
                    if (flag > 0)
                    {
                        moveVirus(x, y);
                    }
                }
            }

            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    if (cntOfVirusGroup[x][y] > 0)
                    {
                        setVirus(x, y);
                    }
                }
            }
        }

        // cout << "debugging---------------" << endl;
        // for (int x = 0; x < n; x++)
        // {
        //     for (int y = 0; y < n; y++)
        //     {
        //         cout << virusMap[x][y].cntOfVirus << " ";
        //     }
        //     cout << endl;
        // }

        int ans = 0;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
            {
                Virus v = virusMap[x][y];
                ans += v.cntOfVirus;
            }
        }

        printf("#%d %d\n", tc, ans);
    }

    return 0;
}