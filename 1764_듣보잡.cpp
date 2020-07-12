#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

set<string> notListend;
set<string> notSeen;
set<string> nameList;
vector<string> ans;

int main() {

    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    
    cin >> n >> m;
    string name;
    for(int i = 0; i < n; i++) {
        cin >> name;
        notListend.insert(name);
        nameList.insert(name);
    }

    for(int i = 0; i < m; i++) {
        cin >> name;
        notSeen.insert(name);
        if(nameList.find(name) == nameList.end()) {
            nameList.insert(name);
        }
    }

    for(auto person : nameList) {
        if((notListend.find(person) != notListend.end()) && (notSeen.find(person) != notSeen.end())) {
            ans.push_back(person);
        }
    }

    sort(ans.begin(), ans.end());

    int numOfPeople = ans.size();
    printf("%d\n", numOfPeople);
    for(auto answer : ans) {
        cout << answer << endl;
    }

    return 0;
}