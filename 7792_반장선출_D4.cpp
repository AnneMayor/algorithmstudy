#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 105;

vector<string> nameList;
int cntOfAlpha[26];

int main()
{

    cout.tie(NULL);

    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        scanf("%d", &n);

        char name[MAX];
        nameList.clear();

        for (int i = 0; i < n; i++)
        {
            scanf(" %[^\n]", name);

            int len = strlen(name);
            string tmp = "";
            for (int i = 0; i < len; i++)
            {
                tmp += name[i];
            }

            nameList.push_back(tmp);
        }

        sort(nameList.begin(), nameList.end());

        int mx = -1;
        int ans = -1;
        for(int i = 0; i < n; i++) {
            memset(cntOfAlpha, 0, sizeof(cntOfAlpha));

            int lenS = nameList[i].length();

            for(int j = 0; j < lenS; j++) {
                if(nameList[i].at(j) == ' ') continue;
                cntOfAlpha[nameList[i].at(j) - 'A']++;
            }

            int type = 0;
            for(int i = 0; i < 26; i++) {
                if(cntOfAlpha[i] > 0) type++;
            }

            if(mx < type) {
                mx = type;
                ans = i;
            }
        }

        cout << "#" << tc << " " << nameList[ans] << endl;

        
    }

    return 0;
}