#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 15;

bool isChecked[4][MAX]; // 0: S , 1: D, 2: H, 3: C
char str[MAX];

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%s", str);

        int len = strlen(str);
        memset(isChecked, false, sizeof(isChecked));

        bool flag = false;
        printf("#%d ", tc);
        for (int i = 0; i < len - 2; i += 3)
        {
            switch (str[i])
            {
            case 'S':
                if (str[i + 1] == '0')
                {
                    if (!isChecked[0][str[i + 2] - '0'])
                    {
                        isChecked[0][str[i + 2] - '0'] = true;
                    }
                    else
                    {
                        printf("ERROR\n");
                        flag = true;
                        break;
                    }
                }
                else
                {
                    if (!isChecked[0][str[i + 2] - '0' + 10])
                    {
                        isChecked[0][str[i + 2] - '0' + 10] = true;
                    }
                    else
                    {
                        printf("ERROR\n");
                        flag = true;
                        break;
                    }
                }
                break;

            case 'D':
                if (str[i + 1] == '0')
                {
                    if (!isChecked[1][str[i + 2] - '0'])
                    {
                        isChecked[1][str[i + 2] - '0'] = true;
                    }
                    else
                    {
                        printf("ERROR\n");
                        flag = true;
                        break;
                    }
                }
                else
                {
                    if (!isChecked[1][str[i + 2] - '0' + 10])
                    {
                        isChecked[1][str[i + 2] - '0' + 10] = true;
                    }
                    else
                    {
                        printf("ERROR\n");
                        flag = true;
                        break;
                    }
                }
                break;

            case 'H':
                if (str[i + 1] == '0')
                {
                    if (!isChecked[2][str[i + 2] - '0'])
                    {
                        isChecked[2][str[i + 2] - '0'] = true;
                    }
                    else
                    {
                        printf("ERROR\n");
                        flag = true;
                        break;
                    }
                }
                else
                {
                    if (!isChecked[2][str[i + 2] - '0' + 10])
                    {
                        isChecked[2][str[i + 2] - '0' + 10] = true;
                    }
                    else
                    {
                        printf("ERROR\n");
                        flag = true;
                        break;
                    }
                }
                break;

            case 'C':
                if (str[i + 1] == '0')
                {
                    if (!isChecked[3][str[i + 2] - '0'])
                    {
                        isChecked[3][str[i + 2] - '0'] = true;
                    }
                    else
                    {
                        printf("ERROR\n");
                        flag = true;
                        break;
                    }
                }
                else
                {
                    if (!isChecked[3][str[i + 2] - '0' + 10])
                    {
                        isChecked[3][str[i + 2] - '0' + 10] = true;
                    }
                    else
                    {
                        printf("ERROR\n");
                        flag = true;
                        break;
                    }
                }
                break;
            }

            if (flag)
                break;
        }

        if(!flag) {
            for(int i = 0; i < 4; i++) {
                int cnt = 0;
                for(int j = 1; j <= 13; j++) {
                    if(isChecked[i][j]) cnt += 1;
                }
                printf("%d ", 13-cnt);
            }
            printf("\n");
        }
    }

    return 0;
}