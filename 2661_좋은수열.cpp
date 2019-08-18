#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 85;

char ans[MAX];
bool flag;

bool isGoodSequence(char str[], int len)
{

    // for (int i = 0; i < len; i++)
    // {
    //     cout << str[i] << " ";
    // }
    // cout << endl;

    bool flag = true;

    for (int i = 1; i <= len / 2; i++)
    {
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (str[len - 1 - j] == str[len - 1 - j - i])
            {
                cnt += 1;
            }
        }

        if (cnt == i)
        {
            flag = false;
            return flag;
        }
    }

    // cout << "flag: " << flag << endl;

    return flag;
}

void solve(int n, int curLen, char nums[])
{
    if(flag) return;

    if (curLen >= n)
    {
        flag = true;

        // for (int i = 0; i < n; i++)
        // {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        // for (int i = 0; i < n; i++)
        // {

        //     if (ans[i] == '0')
        //     {
        //         ans[i] = nums[i];
        //     }
        // }

        if (isGoodSequence(nums, n))
        {

            for (int i = 0; i < n; i++)
            {

                if (ans[i] == '0')
                {
                    ans[i] = nums[i];
                }
            }
        }

        return;
    }

    nums[curLen] = '1';
    if (isGoodSequence(nums, curLen + 1))
    {
        solve(n, curLen + 1, nums);
    }

    nums[curLen] = '2';
    if (isGoodSequence(nums, curLen + 1))
    {
        solve(n, curLen + 1, nums);
    }

    nums[curLen] = '3';
    if (isGoodSequence(nums, curLen + 1))
    {
        solve(n, curLen + 1, nums);
    }
}

int main()
{

    int n;
    scanf("%d", &n);
    flag = false;

    char numSequence[n];
    memset(ans, '0', sizeof(ans));
    memset(numSequence, '0', sizeof(numSequence));

    solve(n, 0, numSequence);

    for (int i = 0; i < n; i++)
    {
        printf("%c", ans[i]);
    }
    printf("\n");

    return 0;
}