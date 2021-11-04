#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

string s;
set<string> group;
int isChecked[3];
vector<char> current;

void recursiveSearch(int cnt);

int main(void) {
    
    cin >> s;

    memset(isChecked, 0, sizeof(isChecked));

    for(int i = 0; i < 3; i++) {
        isChecked[i] = 1;
        current.push_back(s[i]);
        recursiveSearch(1);
        isChecked[i] = 0;
        current.pop_back();
    }

    printf("%d\n", group.size());
    return 0;
}

void recursiveSearch(int cnt) {
    if(cnt >= 3) {
        string res = "";
        for(char c : current) {
            res += c;
        }
        group.insert(res);

        return ;
    }

    for(int i = 0; i < 3; i++) {
        if(!isChecked[i]) {
            isChecked[i] = 1;
            current.push_back(s[i]);
            recursiveSearch(cnt+1);
            isChecked[i] = 0;
            current.pop_back();
        }
    }

    return ;
}