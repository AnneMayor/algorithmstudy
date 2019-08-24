#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1005;

vector<string> ans;
char str[MAX];

int main() {

    cout.tie(NULL);
    scanf("%s", str);

    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        string tmp = "";
        for(int j = i; j < len; j++) {
            tmp += str[j];
        }
        ans.push_back(tmp);
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}