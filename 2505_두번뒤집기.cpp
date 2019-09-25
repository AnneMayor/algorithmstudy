#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10005;

int numArr[MAX];
int reverseArr[MAX];
vector<pair<int, int> > ansList;

int main()
{

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &numArr[i]);
        reverseArr[i] = numArr[i];
    }

    // 순방향 검사
    for (int time = 0; time < 2; time++)
    {
        int start = -1, end = -1;
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            if (numArr[i] != i)
            {
                start = i;
                for (int j = 1; j <= n; j++)
                {
                    if (numArr[j] == i)
                    {
                        end = j;
                        flag = true;
                        break;
                    }
                }
            }

            if (flag)
                break;
        }

        if (start != -1 && end != -1)
        {
            ansList.push_back(make_pair(start, end));
            vector<int> tmp;

            for (int j = end; j >= start; j--)
            {
                tmp.push_back(numArr[j]);
            }

            for (int j = start; j <= end; j++)
            {
                numArr[j] = tmp[j - start];
            }
        } else ansList.push_back(make_pair(1, 1));
    }

    // 배열 검사
    bool flag = true;
    for(int i = 1; i <= n; i++) {
        if(numArr[i] != i) {
            flag = false;
            break;
        }
    }

    if(flag) {
        for(int i = 0; i < 2; i++) {
            printf("%d %d\n", ansList[i].first, ansList[i].second);
        }

        return 0;
    } else {
        ansList.clear();
    }

    // 역방향 검사
    for (int time = 0; time < 2; time++)
    {
        int start = -1, end = -1;
        bool flag = false;
        for (int i = n; i >= 1; i--)
        {
            if (reverseArr[i] != i)
            {
                start = i;
                for (int j = 1; j <= n; j++)
                {
                    if (reverseArr[j] == i)
                    {
                        end = j;
                        flag = true;
                        break;
                    }
                }
            }

            if (flag)
                break;
        }

        if (start != -1 && end != -1)
        {
            ansList.push_back(make_pair(end, start));
            vector<int> tmp;

            for (int j = start; j >= end; j--)
            {
                tmp.push_back(reverseArr[j]);
            }

            for(int j = 0; j < tmp.size(); j++) {
                reverseArr[j+end] = tmp[j];
            }

        } else ansList.push_back(make_pair(1, 1));
    }

    // 배열 검사
    flag = true;
    for(int i = 1; i <= n; i++) {
        if(reverseArr[i] != i) {
            flag = false;
            break;
        }
    }

    if(flag) {
        for(int i = 0; i < 2; i++) {
            printf("%d %d\n", ansList[i].first, ansList[i].second);
        }
    }

    return 0;
}