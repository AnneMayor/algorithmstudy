#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 101;

int str[MAX];
bool isChecked[MAX];
int n;

void findSameWords(int start, int end)
{

    while (start >= 0 && end < n)
    {
        if (!isChecked[start] && !isChecked[end])
        {
            if (str[start] == str[end])
            {
                isChecked[start] = true;
                isChecked[end] = true;
                start--;
                end++;
            }
            else
                break;
        }
        else
        {
            if (isChecked[start])
            {
                start--;
            }
            else if (isChecked[end])
            {
                end++;
            }
            else if (isChecked[start] && isChecked[end])
            {
                start--;
                end++;
            }
            else
                break;
        }
    }
}

int main()
{

    for (int tc = 1; tc <= 10; tc++)
    {
        scanf("%d", &n);

        memset(isChecked, false, sizeof(isChecked));

        for (int i = 0; i < n; i++)
        {
            scanf("%1d", &str[i]);
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (!isChecked[i] && !isChecked[i + 1])
            {
                if (str[i] == str[i + 1])
                {
                    isChecked[i] = true;
                    isChecked[i + 1] = true;
                    findSameWords(i, i + 1);
                }
            }
        }

        printf("#%d ", tc);
        for (int i = 0; i < n; i++)
        {
            if (!isChecked[i])
                printf("%d", str[i]);
        }
        printf("\n");
    }

    return 0;
}