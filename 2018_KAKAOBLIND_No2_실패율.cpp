#include <string>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 505;

int cntOfClearedStage[MAX];
int cntOfChanllengingPeople[MAX];
vector<pair<double, int> > order;

bool comp(const pair<double, int> &s1, const pair<double, int> &s2) {
   if(s1.first > s2.first) return true;
    else if(s1.first == s2.first) {
        if(s1.second < s2.second) return true;
    }
    
    return false;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    memset(cntOfClearedStage, 0, sizeof(cntOfClearedStage));
    memset(cntOfChanllengingPeople, 0, sizeof(cntOfChanllengingPeople));
    
    for(int i = 0; i < stages.size(); i++) {
        for(int j = 1; j < stages[i]; j++) {
            cntOfClearedStage[j]++;
        }
    }
    
    for(int i = 0; i < stages.size(); i++) {
        for(int j = 1; j <= stages[i]; j++) {
            cntOfChanllengingPeople[j]++;
        }
    }
    
    for(int i = 1; i <= N; i++) {
        double total = cntOfChanllengingPeople[i];
        double people = cntOfChanllengingPeople[i] - cntOfClearedStage[i];
        double percentage;
        if(total == 0) {
            percentage = 0;
        } else {
            percentage = people / total;
        }
        order.push_back(make_pair(percentage, i));
    }
    
    sort(order.begin(), order.end(), comp);
    
    for(int i = 0; i < order.size(); i++) {
        answer.push_back(order[i].second);
    }
    
    return answer;
}