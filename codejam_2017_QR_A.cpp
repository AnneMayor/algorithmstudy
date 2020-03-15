#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string pencakes;

bool flipPencake(int start, int k, int limit) {

    if(start + k > limit) return false;

    for(int i = start; i < start+k; i++) {
        if(pencakes[i] == '+') {
            pencakes[i] = '-';
        }
        else pencakes[i] = '+';
    }
    return true;
}

int main() {

    cin.tie(NULL);
    
    int T;
    scanf("%d", &T);

    string outputFilePath = "output.txt";
    ofstream writeFile(outputFilePath);

    for(int tc = 1; tc <= T; tc++) {
        int k;
        cin >> pencakes >> k;
        int pLen = pencakes.length();
        bool flag = true;
        int cntOfFlip = 0;
        while (flag)
        {
            flag = false;
            for(int i = 0; i < pLen; i++) {
                if(pencakes[i] == '-') {
                    cntOfFlip++;
                    flag = flipPencake(i, k, pLen);
                    break;
                }
            }
        }

        bool ansFlag = true;
        for(int i = 0; i < pLen; i++) {
            if(pencakes[i] == '-') {
                ansFlag = false;
                break;
            }
        }

        if(writeFile.is_open()) {
            if(ansFlag) {
                printf("Case #%d: %d\n", tc, cntOfFlip);
                writeFile << "Case #"<< tc << ": " << cntOfFlip << "\n";
            }
            else {
                printf("Case #%d: IMPOSSIBLE\n", tc);
                writeFile << "Case #" << tc << ": IMPOSSIBLE\n"; 
            }
        }
    }

    writeFile.close();

    return 0;
}