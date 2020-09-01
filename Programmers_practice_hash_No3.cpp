#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int ans = 1;

    multimap<string, string> group;
    vector<string> typeList;
    for(auto cloth : clothes) {
        if(group.find(cloth[1]) == group.end()) {
            typeList.push_back(cloth[1]);
        }
        group.insert(make_pair(cloth[1], cloth[0]));
    }

    for(auto type : typeList) {
        ans *= (group.count(type) + 1);
    }

    ans -= 1;
    return ans;
}