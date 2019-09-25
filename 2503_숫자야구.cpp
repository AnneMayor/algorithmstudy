#include <iostream>
#include <cstring>
#include <queue>
#include <string>

using namespace std;
queue<string> readyList;
bool isChecked[10];

void dfs(string num, int cnt, int cntOfStrike, int cntOfBall, string str) {
    if(cnt >= 3) {
        int tmpStrike = 0, tmpBall = 0;
        for(int i = 0; i < 3; i++) {
            if(num[i] == str[i]) {
                tmpStrike++;
            } else if(isChecked[str[i]-'0']) tmpBall++;
        }

        if(tmpStrike == cntOfStrike && tmpBall == cntOfBall) readyList.push(num);
        return;
    }

    for(int i = 1; i <= 9; i++) {
        if(!isChecked[i]) {
            isChecked[i] = true;
            num += i+'0';
            dfs(num, cnt+1, cntOfStrike, cntOfBall, str);
            num.pop_back();
            isChecked[i] = false;
        }
    }

    return ;
}

int main() {

    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++)
    {
        string num;
        cin >> num;

        int cntOfStrike, cntOfBall;
        cin >> cntOfStrike >> cntOfBall;

        if(readyList.empty()) {
            if(tc > 1) {
                printf("0\n");
                return 0;
            }

            memset(isChecked, false, sizeof(isChecked));
            string tmp = "";
            for(int i = 1; i <= 9; i++) {
                isChecked[i] = true;
                tmp += i + '0';
                dfs(tmp, 1, cntOfStrike, cntOfBall, num);
                isChecked[i] = false;
                tmp.pop_back();
            }
        } else {
            int qSize = readyList.size();
            for(int i = 0; i < qSize; i++) {
                int tmpStrike = 0, tmpBall = 0;
                string tmp = readyList.front();
                readyList.pop();

                memset(isChecked, false, sizeof(isChecked));
                for(int i = 0 ; i < 3; i++) {
                    isChecked[tmp[i]-'0'] = true;
                }

                for(int i = 0; i < 3; i++) {
                    if(num[i] == tmp[i]) {
                        tmpStrike++;
                    } else {
                        if(isChecked[num[i]-'0']) tmpBall++;   
                    }
                }

                if(tmpStrike == cntOfStrike && tmpBall == cntOfBall) {
                    readyList.push(tmp);
                }
            }
        }
    }

    printf("%lu\n", readyList.size());
    
    return 0;
}