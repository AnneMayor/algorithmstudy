#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 105;

int map[MAX][MAX];

int main()
{

    for (int tc = 1; tc <= 10; tc++)
    {
        int n;
        scanf("%d", &n);

        for (int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++) {
                scanf("%d", &map[i][j]);
            }
        }

        int cnt = 0;
        for(int j = 0; j < n; j++) {
            int check = 0; // 걸림돌 체크
            for(int i = 0; i < n; i++) {
                if(check == 0 && map[i][j] == 2) {
                    continue;
                } else if(check >= 1 && map[i][j] == 2) {
                    cnt++;
                    check = 0;
                } else if(map[i][j] == 1) {
                    check++;
                }
            }
        }

        printf("#%d %d\n", tc, cnt);

    }

    return 0;
}