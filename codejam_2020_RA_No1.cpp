#include <bits/stdc++.h>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int T;
  cin >> T;

  for(int tc = 1; tc <= T; tc++) {
    int n;
    cin >> n;

    vector<string> stList;
    for(int i = 0; i < n; i++) {
      string s;
      cin >> s;
      stList.push_back(s);
    }

    bool flag = true;
    string pre, post, middle;
    for(int i = 0; i < n; i++) {
      int sLength = stList[i].length();
      int start = 0, last = sLength-1, cntSuffix = 0;
      // prefix
      for(int j = 0; j < sLength; j++) {
        if(stList[i][j] == '*') break;
        if(pre.length() == j) pre += stList[i][j];
        if(pre[j] != stList[i][j]) {
          flag = false;
          break;
        }
        start++;
      }

      // suffix
      for(int j = sLength-1; j >= 0; j--) {
        if(stList[i][j] == '*') break;
        if(post.length() == cntSuffix) post += stList[i][j];
        if(post[cntSuffix] != stList[i][j]) {
          flag = false;
          break;
        }
        cntSuffix++;
        last--;
      }

      // middle
      for(int j = start ; j < last; j++) {
        if(stList[i][j] != '*') {
          middle += stList[i][j];
        }
      }
    }
    
    // cout << "pre: " << pre << " / middle: " << middle << " / post: " << post << endl;
    reverse(post.begin(), post.end());
    cout << "Case #" << tc << ": ";

    if(flag) {
      cout << pre << middle << post << endl;
    } else {
      cout << "*" << endl;
    }
  }

  return 0;
}