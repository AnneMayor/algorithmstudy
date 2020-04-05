#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1005;

struct activity {
    int start;
    int end;
    int idx;
};

bool comp (activity & ac1, activity & ac2) {
    return ac1.start < ac2.start;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;

        vector<activity> activities; // first: endTime , second: startTime
        activity ac;
        for(int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            ac.start = s;
            ac.end = e;
            ac.idx = i;
            activities.push_back(ac);
        }

        sort(activities.begin(), activities.end(), comp);

        int curCameronEndTime = 0, curJamieEndTime = 0;
        char ans[MAX];
        bool ansFlag = true;
        for(int i = 0; i < n; i++) {
            bool flag = false;

            if(curCameronEndTime <= activities[i].start) {
                flag = true;
                curCameronEndTime = activities[i].end;
                ans[activities[i].idx] = 'C';
            } else if(curJamieEndTime <= activities[i].start) {
                flag = true;
                curJamieEndTime = activities[i].end;
                ans[activities[i].idx] = 'J';
            }

            if(!flag) {
                ansFlag = flag;
                break;
            }
        }

        if(!ansFlag) {
            cout << "Case #" << tc << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << tc << ": ";
            for(int i = 0; i < n; i++) {
                cout << ans[i];
            }
            cout << endl;
        }
    }

    return 0;
}