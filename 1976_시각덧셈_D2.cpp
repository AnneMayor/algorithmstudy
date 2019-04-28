#include <iostream>

using namespace std;

int main() {

    int T;
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    for(int t = 1; t <= T; t++) {

        int h1, h2, m1, m2;
        cin >> h1 >> m1 >> h2 >> m2;

        int ansH = h1+h2;
        int ansM = m1+m2;

        if(ansM >= 60) {
            ansH += ansM / 60;
            ansM = ansM % 60;
        }

        if(ansH > 12) {
            if(ansH % 12 == 0) {
                ansH = 12;
            } else {
                ansH %= 12;
            }
        }

        cout << "#" << t << " " << ansH << " " << ansM << endl;

    }

    return 0;
}