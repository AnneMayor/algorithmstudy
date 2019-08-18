#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
const int MAX = 105;

string d[MAX][MAX];

string addToString(string s1, string s2)
{

    string result = "";

    int len1 = s1.length();
    int len2 = s2.length();

    int minLen = min(len1, len2);

    int q = 0;
    for (int i = 1; i <= minLen; i++)
    {
        int tmp = (s1.at(len1 - i) - '0') + (s2.at(len2 - i) - '0') + q;
        q = 0;
        if (tmp / 10 > 0)
        {
            q = tmp / 10;
            result += to_string(tmp % 10);
        }
        else
        {
            result += to_string(tmp);
        }
    }

    if (len1 - minLen > 0)
    {
        for (int i = len1 - minLen - 1; i >= 0; i--)
        {
            int tmp = (s1.at(i) - '0') + q;
            q = 0;
            if (tmp / 10 > 0)
            {
                q = tmp / 10;
                result += to_string(tmp % 10);
            }
            else
            {
                result += to_string(tmp);
            }
        }
    }
    else if (len2 - minLen > 0)
    {
        for (int i = len2 - minLen - 1; i >= 0; i--)
        {
            int tmp = (s2.at(i) - '0') + q;
            q = 0;
            if (tmp / 10 > 0)
            {
                q = tmp / 10;
                result += to_string(tmp % 10);
            }
            else
            {
                result += to_string(tmp);
            }
        }

    }

    if(q > 0) result += to_string(q);

    reverse(result.begin(), result.end());

    return result;
}

int main()
{

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
            {
                d[i][j] = to_string(i);
            }
            else if (i == j)
            {
                d[i][j] = "1";
            }
            else
            {
                d[i][j] = addToString(d[i - 1][j - 1], d[i - 1][j]);
            }
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << d[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << d[n][m] << endl;

    return 0;
}