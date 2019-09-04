#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 101;

char words[MAX][MAX];
vector<int> character;
int cntOfAlpha1[26];
int cntOfAlpha2[26];

int main()
{

    int n;
    scanf("%d", &n);
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", words[i]);
    }

    memset(cntOfAlpha1, 0, sizeof(cntOfAlpha1));
    int lenW1 = strlen(words[0]);
    for (int w1 = 0; w1 < lenW1; w1++)
    {
        cntOfAlpha1[words[0][w1] - 'A']++;
    }

    for (int j = 1; j < n; j++)
    {
        bool flag = true;
        character.clear();
        memset(cntOfAlpha2, 0, sizeof(cntOfAlpha2));

        int lenW2 = strlen(words[j]);
        for (int w2 = 0; w2 < lenW2; w2++)
        {
            cntOfAlpha2[words[j][w2] - 'A']++;
        }

        for(int i = 0; i < 26; i++) {
            if(cntOfAlpha1[i] != cntOfAlpha2[i]) character.push_back(i);
        }

        if(character.size() >= 3) {
            flag = false;
        } else if(character.size() == 2) {
            int alpha1 = 0;
            int alpha2 = 0;
            for(int s = 0; s < character.size(); s++) {
                alpha1 += cntOfAlpha1[character[s]];
                alpha2 += cntOfAlpha2[character[s]];
            }

            if(alpha1 != alpha2) flag = false;
        } else {
            for(int s = 0; s < character.size(); s++) {
                if(abs(cntOfAlpha1[character[s]] - cntOfAlpha2[character[s]]) > 1) {
                    flag = false;
                    break;
                }
            }
        }

        if(flag) {
            ans++;
        }

    }

    printf("%d\n", ans);

    return 0;
}