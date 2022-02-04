#include <iostream>
#include <string>

using namespace std;

// Point: 2개 문자를 삭제하기 위한 시작점을 잘 선택해야한다!
int main(void)
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s >> t;
        int n = s.length();
        int m = t.length();

        if (n < m)
            printf("NO\n");
        else
        {
            // Point 1
            int p = (n-m) & 1;
            int q = 0;
            int k = 0;
            for (int i = p; i < n; i++)
            {
                // Point 2
                if (k == 1)
                {
                    k = 0;
                    continue;
                }
                if (q < m && s[i] == t[q])
                {
                    q++;
                }
                else
                {
                    k++;
                }
            }

            if(q == m) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}