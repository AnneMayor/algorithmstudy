#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    vector<vector<int> > answer{};
    unordered_set<int> numGroup;

    int n = array.size();

    sort(array.begin(), array.end());
    
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            int currentSum = array[i] + array[j];
            int diff = targetSum - currentSum;
            if(numGroup.find(diff) != numGroup.end()) {
                answer.push_back({diff, array[i], array[j]});

            }
        }
        numGroup.insert(array[i]);
    }

    sort(answer.begin(), answer.end());

  return answer;
}