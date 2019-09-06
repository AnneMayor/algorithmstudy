#include <string>
#include <set>
#include <vector>

using namespace std;

vector<int> colList;

bool isValid(int idx) {
    for(int i = 0; i < colList.size(); i++) {
        if((colList[i]&idx) == colList[i]) {
            return false;
        }
    }

    return true;
}

int solution(vector<vector<string>> relation) {

    int n = relation.size();
    int m = relation[0].size();

    colList.clear();

    for(int i = 1; i < (1 << m); i++) {
        set<string> group;
        for(int j = 0; j < n; j++) {
            string key = "";
            for(int k = 0; k < m; k++) {
                if(i&(1<<k)) key += relation[j][k];
            }
            group.insert(key);
        }
        if(group.size() == n && isValid(i)) colList.push_back(i);
    }



    return colList.size();
}