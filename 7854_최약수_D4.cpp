#include <iostream>

using namespace std;

int pow(int two, int five)
{
    int ret = 1;

    // 2의 거듭제곱
    int fact = 2;
    while (two)
    {
        if (two & 1)
        {
            ret *= fact;
        }
        fact *= fact;
        two >>= 1;
    }

    // 5의 거듭제곱
    fact = 5;
    while (five)
    {
        if (five & 1)
        {
            ret *= fact;
        }
        fact *= fact;
        five >>= 1;
    }

    return ret;
}

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        scanf("%d", &n);

        int cntOfTwo = 0, cntOfFive = 0;
        int tmp = 1;
        int cntOfAns = 0;
        int tmpCntTwo = 0;
        while (tmp <= n)
        {
            cntOfAns++;
            if (cntOfFive + 1 <= cntOfTwo)
            {
                cntOfFive++;
                if (cntOfFive >= 4)
                {
                    tmpCntTwo++;
                    cntOfTwo = tmpCntTwo;
                } else {
                    cntOfTwo = 0;
                }
            }
            else
            {
                cntOfTwo++;
            }

            // cout << "cntOfFive: " << cntOfFive << " / cntOfTwo: " << cntOfTwo << endl;
            tmp = pow(cntOfTwo, cntOfFive);
        }

        printf("#%d %d\n", tc, cntOfAns);
    }

    return 0;
}