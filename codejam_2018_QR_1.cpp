#include <iostream>
#include <string>

using namespace std;

long long d;
string p;

long long getCurrentScore()
{
    int pLen = p.length();
    long long curScore = 0;
    int charge = 1;
    for (int i = 0; i < pLen; i++)
    {
        if (p[i] == 'C')
        {
            charge <<= 1;
        }
        else
        {
            curScore += charge;
        }
    }

    return curScore;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> d >> p;

        int pLen = p.length();
        int ans = 0;

        while (getCurrentScore() > d)
        {
            bool isChanged = false;
            for(int i = pLen-2; i >= 0; i--) {
                if(p[i] == 'C' && p[i+1] == 'S') {
                    p[i+1] = 'C';
                    p[i] = 'S';
                    ans++;
                    isChanged = true;
                }
                if(isChanged) break;
            }

            if(!isChanged) break;
        }

        if(getCurrentScore() > d) {
            cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << tc << ": " << ans << endl;
        }
        
    }

    return 0;
}