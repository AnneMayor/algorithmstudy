#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;
set<string> wordsGroups;
const int MAX = 20005;

int wordsLength[MAX];
string words[MAX];
bool isChecked[MAX];

int main() {

    int n;
    scanf("%d", &n);

    cin.ignore();
    cin.tie(0); cout.tie(0);

    memset(wordsLength, 0, sizeof(wordsLength));
    memset(isChecked, false, sizeof(isChecked));

    int idx = 0;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        if(wordsGroups.empty() || wordsGroups.count(temp) == 0 ) {
            wordsGroups.insert(temp);
            words[idx] = temp;
            wordsLength[idx] = temp.length();
            idx++;
        }
    }

    

    sort(wordsLength, wordsLength+idx);
    sort(words, words+idx);

    for(int i = 0; i < idx; i++) {
        for(int j = 0; j < idx; j++) {
            if(!isChecked[j] && wordsLength[i] == words[j].length()) {
                isChecked[j] = true;
                cout << words[j] << endl;
            }
        }
    }

    return 0;
}