#include <iostream>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        string s;
        cin >> s;

        string ans = "";
        int len = s.length();
        int numOfCurParenthesis = 0;
        for(int i = 0; i < len; i++) {
            int sNum = s.at(i) - '0';
            if(numOfCurParenthesis < sNum) {
                for(int j = numOfCurParenthesis; j < sNum; j++) {
                    ans.append("(");
                    numOfCurParenthesis++;
                }
            } else if(numOfCurParenthesis > sNum){
                for(int j = numOfCurParenthesis; j > sNum; j--) {
                    ans.append(")");
                    numOfCurParenthesis--;
                }
            }
            ans += s.at(i);
        }

        for(int i = 0; i < numOfCurParenthesis; i++) {
            ans.append(")");
        }
        
        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}