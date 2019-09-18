#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int MAX = 1e5;

int S;
int ans;

struct emogi {
    int view;
    int clip;
    int time;
};

queue<emogi> q;
bool isChecked[MAX];
bool isCliped[MAX];

void bfs(int view, int clip, int time) {
    emogi e;
    e.view = view;
    e.clip = clip;
    e.time = time;
    q.push(e);

    while (!q.empty())
    {
        view = q.front().view;
        clip = q.front().clip;
        time = q.front().time;
        q.pop();

        isChecked[view] = true;
        isCliped[clip] = true;
        
        if(view == S) {
            if(ans > time) ans = time;
            return;
        }

        // cout << "view: " << view << " / clip: " << clip << " / time: " << time << endl;

        if(view > 0 && !isCliped[view]) {
            e.view = view;
            e.clip = view;
            e.time = time+1;
            q.push(e);
        }

        if(clip > 0) {
            e.view = view+clip;
            e.clip = clip;
            e.time = time+1;
            q.push(e);
        }

        if(view-1 >= 0 && !isChecked[view-1]) {
            e.view = view-1;
            e.clip = clip;
            e.time = time+1;
            q.push(e);
        }
    }

    return ;
    
}

int main() {

    scanf("%d", &S);
    ans = 1e9;
    memset(isChecked, false, sizeof(isChecked));
    memset(isCliped, false, sizeof(isCliped));

    bfs(1, 0, 0);

    printf("%d\n", ans);

    return 0;
}