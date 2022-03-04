#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {

    int n = gems.size();
    vector<int> answer = {1, n};

    int codeIdx = 0;
    vector<int> gemCode;
    map<string, int> gemType;
    for(string gem : gems) {
        if(gemType.count(gem) == 0) {
            gemType.insert(make_pair(gem, codeIdx));
            gemCode.push_back(codeIdx++);
        } else {
            gemCode.push_back(gemType.at(gem));
        }
    }

    vector<int> have(codeIdx);
    int end = 0;
    for(int start = 0; start < n; start++) {
        bool flag = true;
        while (find(have.begin(), have.end(), 0) != have.end())
        {
            if(end >= n) {
                flag = false;
                break;
            }
            
            have[gemCode[end++]]++;
        }

        if(flag && end - (start + 1) < answer[1] - answer[0]) {
            answer[0] = start + 1;
            answer[1] = end;
        }
        have[gemCode[start]]--;
    }

    return answer;
}