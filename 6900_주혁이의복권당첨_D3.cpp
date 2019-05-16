#include <iostream>
#define MAX 1005

using namespace std;
char lottery[MAX][8];
int money[MAX];

int main()
{

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {

        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++)
        {
            scanf("%s %d", lottery[i], &money[i]);
        }

        int ans = 0;
        char nums[MAX][8];
        for (int i = 0; i < m; i++)
        {
            scanf("%s", nums[i]);
        }

        // SWExpertAcademy의 경우, 입력받는 값들은 먼저 입력받아 배열에 저장해주고 그걸 꺼내서 답을 구하는 방식으로 알고리즘 짜야함.
        for (int i = 0; i < m; i++)
        {
            // 당첨번호 비교
            int cnt = 0;
            for (int x = 0; x < n; x++)
            {
                cnt = 0;
                for (int y = 0; y < 8; y++)
                {
                    if (lottery[x][y] != '*')
                    {
                        if (nums[i][y] == lottery[x][y])
                        {
                            cnt += 1;
                        }
                    }
                    else
                    {
                        cnt += 1;
                    }
                }

                cout << "cnt: " << cnt << endl;

                if (cnt == 8)
                {
                    ans += money[x];
                    cout << "ans: " << ans << endl;
                    break;
                }
            }
        }

        printf("#%d %d\n", t, ans);
    }

    return 0;
}