#include <vector>
#include <cmath>

using namespace std;

// O(n) Time | O(n) space
int minRewards(vector<int> scores) {
  int totalMinRewards = 0;

  int n = scores.size();
  vector<int> rewards(n, 1);

  // 1. Compare each score from left to right
  for(int i = 0; i < n-1; i++) {
    if(scores[i] < scores[i+1]) {
      rewards[i+1] = max(rewards[i+1], rewards[i]+1);
    }
  }

  // 2. Compare each score from right to left
  for(int i = n-1; i >= 1; i--) {
    if(scores[i] < scores[i-1]) {
      rewards[i-1] = max(rewards[i-1], rewards[i] + 1);
    }
  }

  for(int i = 0; i < n; i++) {
    totalMinRewards += rewards[i];
  }

  return totalMinRewards;
}
