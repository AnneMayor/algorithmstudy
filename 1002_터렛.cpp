#include <iostream>

using namespace std;

typedef long long ll;

int checkDistance(ll d, ll r1, ll r2)
{

    int flag = 2;
    ll add = (r1 + r2) * (r1 + r2);
    ll sub = (max(r1, r2) - min(r1, r2)) * (max(r1, r2) - min(r1, r2));

    if (d != 0 && (sub == d || add == d))
        flag = 1;   
    else if (add < d || sub > d)
        flag = 0;
    else if (d == 0)
    {
        if (r1 != r2)
            flag = 0;
        else
            flag = -1;
    }

    return flag;
}

int main()
{

    int T;
    for (scanf("%d", &T); T--;)
    {
        ll x1, y1, r1, x2, y2, r2;
        scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);
        ll distance = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

        printf("%d\n", checkDistance(distance, r1, r2));
    }

    return 0;
}