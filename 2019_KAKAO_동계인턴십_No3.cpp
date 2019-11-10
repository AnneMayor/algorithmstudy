#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;
const int MAX = 15;

vector<int> idxList;
set<string> ansList;
bool isChecked[MAX];

bool isBanned(string uId, string bId) {

    int uLen = uId.length();
    int bLen = bId.length();

    if(uLen != bLen) return false;

    for(int i = 0; i < uLen; i++) {
        if(bId[i] != '*' && uId[i] != bId[i]) return false;
    }

    return true;
}

void searchBannedCase(int start, int cnt, int userLen, int bannedLen, vector<string> & user, vector<string> & banned) {
    if(cnt >= bannedLen) {

        vector<int> tmpIdx;
        for(int i = 0; i < idxList.size(); i++) {
            tmpIdx.push_back(idxList[i]);
        }

        sort(tmpIdx.begin(), tmpIdx.end());

        string tmp = "";
        for(int i = 0; i < idxList.size(); i++) {
            tmp += (tmpIdx[i]+'0');
        }

        ansList.insert(tmp);

        return ;
    }

    for(int i = start; i < userLen; i++) {
        if(!isChecked[i] && isBanned(user[i], banned[cnt])) {
            isChecked[i] = true;
            idxList.push_back(i);
            searchBannedCase(start, cnt+1, userLen, bannedLen, user, banned);
            isChecked[i] = false;
            idxList.pop_back();
        }
    }

    return ;

}

int solution(vector<string> user_id, vector<string> banned_id) {

    memset(isChecked, false, sizeof(isChecked));
    int userIdLen = user_id.size();
    int bannedIdLen = banned_id.size();
    ansList.clear();
    idxList.clear();

    for(int i = 0; i < userIdLen; i++) {
        searchBannedCase(i, 0, userIdLen, bannedIdLen, user_id, banned_id);
    }

    int answer = ansList.size();
    return answer;
}