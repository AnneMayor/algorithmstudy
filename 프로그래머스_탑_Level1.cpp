#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<pair<int, int> > tower;
    int numOfTower = heights.size();
    for(int i = 1; i <= numOfTower; i++) {
        pair<int, int> p;
        p.first = i;
        p.second = heights[i-1];
        while (!tower.empty())
        {
            if(tower.top().second < heights[i-1]) tower.pop();
            else break;
        }
        if(tower.empty() || tower.top().second == p.second) answer.push_back(0);
        else answer.push_back(tower.top().first);
        tower.push(p);
    }
    return answer;
}