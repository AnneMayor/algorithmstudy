#include <iostream>

using namespace std;

int main()
{

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        int d, h, m;
        scanf("%d %d %d", &d, &h, &m);

        if (d <= 11 && h < 11 && m < 11)
        {
            printf("#%d -1\n", tc);
        }
        else
        {
            int timeOfDay = 24 * 60 * ((d - 1) - 11);
            if (timeOfDay < 0)
                timeOfDay = 0;
            int timeOfHour, timeOfMin;
            if (d <= 11)
            {

                if (h < 11)
                {
                    printf("#%d -1\n", tc);
                    continue;
                }
                else
                {

                    if (h == 11)
                    {
                        timeOfHour = 0;
                        if (m < 11)
                        {
                            printf("#%d -1\n", tc);
                            continue;
                        }
                        else
                        {
                            timeOfMin = m - 11;
                        }
                    }
                    else
                    {
                        timeOfHour = 60 * ((h - 1) - 11);
                        timeOfMin = 49 + m;
                    }
                }
            }
            else
            {

                int defaultH = 12 * 60;
                int defaultM = 49;

                timeOfHour = defaultH;
                timeOfMin = defaultM;

                timeOfHour += 60 * h;
                timeOfMin += m;
            }

            printf("#%d %d\n", tc, (timeOfDay + timeOfHour + timeOfMin));
        }
    }

    return 0;
}