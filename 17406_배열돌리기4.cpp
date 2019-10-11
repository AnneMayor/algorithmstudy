#include <iostream>
#include <vector>

using namespace std;
const int MAX = 55;

struct Command
{
    int r;
    int c;
    int s;
};

int tmpArr[MAX][MAX];
int arr[MAX][MAX];
int defaultMap[MAX][MAX];

vector<Command> order;
vector<int> cmdNumber;
int ans;
int checkVisit[MAX];

int n, m, k;

void rotateClockWise(const Command &cmd)
{
    // arr -> tmpArr 복사
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmpArr[i][j] = arr[i][j];
        }
    }

    // 회전
    for (int p = 0; p < cmd.s; p++)
    {
        int startX = cmd.r - cmd.s - 1 + p;
        int startY = cmd.c - cmd.s - 1 + p;
        int endX = cmd.r + cmd.s - 1 - p;
        int endY = cmd.c + cmd.s - 1 - p;

        // 위
        for (int i = endX; i >= startX + 1; i--)
        {
            tmpArr[i - 1][startY] = arr[i][startY];
        }

        // 왼쪽
        for (int i = startY + 1; i <= endY; i++)
        {
            tmpArr[endX][i - 1] = arr[endX][i];
        }

        // 아래
        for (int i = endX; i >= startX+1; i--)
        {
            tmpArr[i][endY] = arr[i-1][endY];
        }

        // 오른쪽
        for (int i = startY; i < endY; i++)
        {
            tmpArr[startX][i + 1] = arr[startX][i];
        }
    }

    // tmpArr -> arr 복사
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = tmpArr[i][j];
        }
    }

    // cout << "debugging----------" << endl;
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < m; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return;
}

void findAns()
{
    int val = 1e7;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        for (int j = 0; j < m; j++)
        {
            tmp += arr[i][j];
        }
        if (val > tmp)
            val = tmp;
    }
    if (ans > val)
        ans = val;

    return ;
}

void findComb(int start, int cnt)
{
    if (cnt >= k)
    {
        // 배열 초기화
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[i][j] = defaultMap[i][j];
            }
        }

        for (int i = 0; i < k; i++)
        {
            Command cmd = order[cmdNumber[i]];
            rotateClockWise(cmd);
        }

        findAns();
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (!checkVisit[i])
        {
            checkVisit[i] = true;
            cmdNumber.push_back(i);
            findComb(i, cnt + 1);
            checkVisit[i] = false;
            cmdNumber.pop_back();
        }
    }

    return;
}

int main()
{

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
            defaultMap[i][j] = arr[i][j];
        }
    }

    ans = 1e7;

    for (int i = 0; i < k; i++)
    {
        Command cmd;
        int r, c, s;
        scanf("%d %d %d", &r, &c, &s);
        cmd.r = r;
        cmd.c = c;
        cmd.s = s;
        order.push_back(cmd);
    }

    // 가능 조합 구하기
    cmdNumber.clear();
    for (int i = 0; i < k; i++)
    {
        checkVisit[i] = true;
        cmdNumber.push_back(i);
        findComb(i, 1);
        checkVisit[i] = false;
        cmdNumber.pop_back();
    }

    printf("%d\n", ans);
}