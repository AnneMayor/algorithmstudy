#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    cin.tie(NULL);

    int T;
    scanf("%d", &T);

    string outputFilePath = "output.txt";
    fstream writeFile(outputFilePath);

    for(int tc = 1; tc <= T; tc++) {
        string numStr;
        cin >> numStr;

        int numLength = numStr.length();
        string ans = "";
        for(int i = numLength-1; i > 0; i--) {
            int next = numStr[i]-'0';
            int prev = numStr[i-1]-'0';
            if(prev > next) {
                ans = "";
                for(int j = i; j < numLength; j++) {
                    ans = '9' + ans;
                }
                numStr[i-1] = prev-1+'0';
            } else {
                char nextChar = next + '0';
                ans = nextChar + ans;
            }
        }

        if(numStr[0]-'0' > 0) ans = numStr[0] + ans;

        printf("Case #%d: %s\n", tc, ans.c_str());
        if(writeFile.is_open()) {
            writeFile << "Case #" << tc << ": " << ans << "\n";
        }
    }

    writeFile.close();

    return 0;
}