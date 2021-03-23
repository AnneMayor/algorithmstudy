#include <vector>

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
    vector<int> oneDimensionArray;

    int n = array.size(), m = array[0].size();
    int count = 1;
    int top = 0, bottom = n-1, left = 0, right = m-1;
    while (true)
    {
        if(count > n*m) break;
        // 1. Top: left -> right
        for(int start = left; start <= right; start++) {
            count++;
            oneDimensionArray.push_back(array[top][start]);
        }
        top++;

        if(count > n*m) break;
        // 2. Top: top -> bottom
        for(int start = top; start <= bottom; start++) {
            count++;
            oneDimensionArray.push_back(array[start][right]);
        }
        right--;

        if(count > n*m) break;
        // 3. Bottom: right -> left
        for(int start = right; start >= left; start--) {
            count++;
            oneDimensionArray.push_back(array[bottom][start]);
        }
        bottom--;

        if(count > n*m) break;
        // 4. Bottom: bottom -> top
        for(int start = bottom; start >= top; start--) {
            count++;
            oneDimensionArray.push_back(array[start][left]);
        }
        left++;
    }
    
  return oneDimensionArray;
}
