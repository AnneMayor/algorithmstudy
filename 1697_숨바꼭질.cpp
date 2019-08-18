#include <iostream>
#include <queue>

using namespace std;

class Pair {

    private:
        int location;
        int minMove;

    public:
        void setLocation(int x) {
            this->location = x;
        }

        void setMinMove(int x) {
            this->minMove = x;
        }

        int getLocation() {
            return this->location;
        }

        int getMinMove() {
            return this->minMove;
        }

};

int n, k;
queue<Pair> q;
bool isChecked[200005];
int ans = 300005;

void bfs(int num, int cnt) {
    
    Pair p;
    p.setLocation(num);
    p.setMinMove(cnt);

    isChecked[num] = true;

    q.push(p);

    while(!q.empty()) {
        
        Pair np = q.front();
        q.pop();

        int l = np.getLocation();
        int m = np.getMinMove();

        if(l != k) {
            
            if(l-1 >= 0 && !isChecked[l-1]) {
                isChecked[l-1] = true;
                np.setLocation(l-1);
                np.setMinMove(m+1);
                q.push(np);
            }
            
            if(l+1 <= 200000 && !isChecked[l+1]) {
                isChecked[l+1] = true;
                np.setLocation(l+1);
                np.setMinMove(m+1);
                q.push(np);
            }
            
            if(2*l <= 200000 && !isChecked[2*l]) {
                isChecked[2*l] = true;
                np.setLocation(2*l);
                np.setMinMove(m+1);
                q.push(np);
            }
            
        } else {

            if(ans > m) {
                ans = m;
            }

            return;

        }

    }

}

int main() {

    scanf("%d %d", &n, &k);

    for(int i = 0; i < 200005; i++) {
        isChecked[i] = false;
    }

    bfs(n, 0);

    printf("%d\n", ans);

    return 0;
}