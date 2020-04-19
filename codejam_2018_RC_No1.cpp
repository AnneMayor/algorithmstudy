#include <bits/stdc++.h>

using namespace std;

set<string> wordsGroup;
vector<string> words;
vector<char> chList;
string ans;
bool recursiveFlag;

bool isInColumn(int alpha, int idxCol, int n) {
    bool result = false;
    alpha += 'A';
    for(int i = 0; i < n; i++) {
        if(alpha == words[i][idxCol]) {
            result = true;
            break;
        }
    }
    return result;
}

void findAns(int length, int l, int n)
{
    if(length == l) {
        string tmp = "";
        for(int i = 0; i < l; i++) {
            tmp += chList[i];
        }
        if(wordsGroup.find(tmp) == wordsGroup.end()) {
            recursiveFlag = true;
            ans = tmp;
            return;
        }
        return ;
    }

    for(int i = 0; i < 26; i++) {
        if(recursiveFlag) return ;
        if(isInColumn(i, length, n)) {
            chList.push_back(i+'A');
            findAns(length+1, l, n);
            chList.pop_back();
        }
    }

    return;
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
        int n, l;
        cin >> n >> l;

        wordsGroup.clear();
        words.clear();
        chList.clear();

        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            words.push_back(s);
            wordsGroup.insert(s);
        }

        ans = "";
        recursiveFlag = false;
        findAns(0, l, n);

        if (ans == "")
            cout << "Case #" << tc << ": -" << endl;
        else
            cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}