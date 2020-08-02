#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 1e5 + 5;

bool isPrime[MAX];
bool isNearlyPrime[MAX];

void findPrime()
{

    for (int i = 2; i <= 1e5; i++)
    {
        bool flag = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (!isPrime[i])
            {
                if ((i % j) == 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            isPrime[i] = true;
    }

    return;
}

void findNearlyPrime()
{

    for (int i = 2; i <= 1e5; i++)
    {
        // 여기 체크
        for (int j = 2; j <= sqrt(i); j++)
        {
            if ((i % j) == 0)
            {
                int num1 = j;
                int num2 = i / j;
                if ((num1 != num2) && isPrime[num1] && isPrime[num2])
                {
                    isNearlyPrime[i] = true;
                    break;
                }
            }
        }
    }

    return;
}

int main()
{

    memset(isPrime, false, sizeof(isPrime));
    memset(isNearlyPrime, false, sizeof(isNearlyPrime));

    // 소수 찾기
    findPrime();

    // nearly prime 찾기
    findNearlyPrime();

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        // 4개의 서로 다른 양수 합 표현 가능여부 판단
        int n;
        scanf("%d", &n);

        if (n-30 > 0)
        {
            printf("YES\n");

            // 예외 케이스 정리(36, 42, 44)
            switch (n)
            {
                case 36:
                printf("6 10 15 5\n");
                break;

                case 40:
                printf("6 10 15 9\n");
                break;

                case 44:
                printf("6 10 15 13\n");
                break;

                default:
                printf("6 10 14 %d\n", n-30);
                break;

            }
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}