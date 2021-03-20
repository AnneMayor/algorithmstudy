  #include <vector>
  #include <map>

  using namespace std;

  // Avarage: O(n^2) time | O(n^2) space
  // Worst: O(n^3) time | O(n^2) space (In terms of time complexity, it is hard to say exactly. This just assumes)

  vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
    map<int, vector<pair<int, int> > > sumOfTwoNum;
    int n = array.size();
    vector<vector<int> > answer;

    for(int i = 0; i < n-1; i++) {
      // 1. Check the map if there is sum of two numbers which is the same as the diff value(after)
      for(int j = i+1; j < n; j++) {
        int currentSum = array[i] + array[j];
        int diff = targetSum - currentSum;
        if(sumOfTwoNum.find(diff) != sumOfTwoNum.end()) {
          vector<pair<int, int> > sumOfList = sumOfTwoNum[diff];
          for(auto p : sumOfList) {
            vector<int> quadruplets;
            quadruplets.push_back(array[i]);
            quadruplets.push_back(array[j]);
            quadruplets.push_back(p.first);
            quadruplets.push_back(p.second);
            answer.push_back(quadruplets);
          }
        }
      }

      // 2. Insert sum of two numbers into map(before)
      for(int k = 0; k < i; k++) {
        int currentSum = array[i] + array[k];
        if(sumOfTwoNum.find(currentSum) != sumOfTwoNum.end()) {
          sumOfTwoNum[currentSum].push_back({array[i], array[k]});
        } else {
          vector<pair<int, int> > p;
          p.push_back({array[i], array[k]});
          sumOfTwoNum.insert(make_pair(currentSum, p));
        }
      }
    }

    return answer;
  }
