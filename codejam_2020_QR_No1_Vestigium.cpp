#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 105;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;

        int numMap[MAX][MAX];
        bool isChecked[MAX];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> numMap[i][j];
            }
        }

        int trace = 0, numOfRepeatedRow = 0, numOfRepeatedCol = 0;

        int sX = 0, sY = 0;
        while (sX < n && sY < n)
        {
            // trace
            trace += numMap[sX][sY];

            memset(isChecked, false, sizeof(isChecked));
            // row 검사
            for(int i = 0; i < n; i++) {
                if(!isChecked[numMap[sX][i]]) isChecked[numMap[sX][i]] = true;
                else {
                    numOfRepeatedRow++;
                    break;
                }
            }
            
            memset(isChecked, false, sizeof(isChecked));
            // col 검사
            for(int i = 0; i < n; i++) {
                if(!isChecked[numMap[i][sY]]) isChecked[numMap[i][sY]] = true;
                else {
                    numOfRepeatedCol++;
                    break;
                }
            }

            sX++;
            sY++;
        }
        
        cout << "Case #" << tc << ": " << trace << " " << numOfRepeatedRow << " " << numOfRepeatedCol << endl;
    }

    return 0;
}