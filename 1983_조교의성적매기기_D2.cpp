#include <iostream>
#include <string>

using namespace std;

int main() {

    int T;
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int t = 1; t <= T; t++) {
        
        int n, k;
        cin >> n >> k;

        int score[n][3];
        double total[n];
        int grade[n];

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 3; j++) {
                cin >> score[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            total[i] = 0.0;
            grade[i] = 0;
        }
        
        for(int i = 0; i < n; i++) {
            total[i] = (score[i][0]*0.35) + (score[i][1]*0.45) + (score[i][2]*0.2);
        }

        int count = 0;
        int gra = 1;
        for(int idx = 1; idx <= n; idx++) {
            double max = -10000;
            int maxIdx = 0;
            for(int i = 0; i < n; i++) {
                if(max < total[i]) {
                    max = total[i];
                    maxIdx = i;
                }
            }

            total[maxIdx] = -10000;
            if(count >= n / 10) {
                gra++;
                grade[maxIdx] = gra;
                count = 0;
            } else {
                grade[maxIdx] = gra;
            }
            count++;
        }

        string ans = "";

        switch (grade[k-1])
        {
        case 1:
            ans = "A+";
            break;

        case 2:
            ans = "A0";
            break;
        
        case 3:
            ans = "A-";
            break;
        
        case 4:
            ans = "B+";
            break;
        
        case 5:
            ans = "B0";
            break;

        case 6:
            ans = "B-";
            break;

        case 7:
            ans = "C+";
            break;

        case 8:
            ans = "C0";
            break;

        case 9:
            ans = "C-";
            break;

        case 10:
            ans = "D0";
            break;
        }

        cout << "#" << t << " " << ans << endl;

    }

    return 0;
}