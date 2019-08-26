#include <iostream>
#include <string>

using namespace std;

#define B1 "FF"
#define B2 "FC"

int main() {

    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        string str;
        cin >> str;

        int idx = 0;
        int len = str.length();
        int flag = -1;
        bool ansFlag = true;
        while(idx < len) {
            
            if(str.substr(idx, 2) == B1) {
                flag = 1;
            } else if(str.substr(idx, 2) == B2) {
                flag = 2;
            } else {
                ansFlag = false;
                break;
            }

            idx += 2;
            int i;
            if(flag == 1) {

                for(i = idx; i < len && str.at(i) != 'M'; i++) {
                    if(str.at(i) != 'F') {
                        ansFlag = false;
                        break;
                    }
                }

                idx = i;


                if(str.substr(idx, 3) != "MCM") {
                    ansFlag = false;
                    break;
                }

                idx += 3;

                for(i = idx; i < len && str.at(i) != 'F'; i++) {
                    if(str.at(i) != 'M') {
                        ansFlag = false;
                        break;
                    }
                }

                idx = i;

            } else if(flag == 2) {
                for(i = idx; i < len && str.at(i) != 'M'; i++) {
                    if(str.at(i) != 'C') {
                        ansFlag = false;
                        break;
                    }
                }

                idx = i;

                if(str.substr(idx, 2) != "MF") {
                    ansFlag = false;
                    break;
                }

                idx += 2;
            }
        }

        printf("#%d ", tc);
        if(ansFlag) {
            printf("DETECTED!\n");
        } else {
            printf("NOTHING!\n");
        }

    }

    return 0;
}