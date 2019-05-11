#include <iostream>

using namespace std;

int main()
{

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++)
    {

        int s, e, m;
        scanf("%d %d %d", &s, &e, &m);

        int ans = 0;
        int div = 24;

        if (s == 365 && e == 24 && m == 29)
        {
            ans = s * e * m;
            printf("#%d %d\n", t, ans);
            
        } else
        {

            while (1)
            {
                if (s == 365 && e == 24)
                {
                    ans += s * e;
                    if (ans % 29 == m)
                        break;
                }
                else if (e == 24 && m == 29)
                {
                    ans += e * m;
                    if (ans % 365 == s)
                        break;
                }
                else if (s == 365 && m == 29)
                {
                    ans += s * m;
                    if (ans % 24 == e)
                        break;
                }
                else if (s == 365)
                {
                    ans += s;
                    if (ans % 24 == e && ans % 29 == m)
                        break;
                }
                else if (e == 24)
                {
                    ans += e;
                    if (ans % 365 == s && ans % 29 == m)
                        break;
                }
                else if (m == 29)
                {
                    ans += m;
                    if (ans % 365 == s && ans % 24 == e)
                        break;
                }
                else
                {
                    if (ans == 0)
                        ans += e;
                    if ((ans % 365 == s) && (ans % 29 == m))
                        break;
                    ans += div;
                }
            }

            printf("#%d %d\n", t, ans);
        }
    }

    return 0;
}