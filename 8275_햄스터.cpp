#include <iostream>
#include <vector>

using namespace std;
const int MAX = 15;

struct Condition {
    int start;
    int end;
    int val;
};

int cntOfHamsters[MAX];
int n, x, m;
vector<Condition> v;
vector<int> ans;

void dfs(int start) {

    if(start > n) {
        bool flag = true;
        int witchone = 0;
        for(int i = 0; i < v.size(); i++) {
            Condition c = v[i];
            int tmp = 0;
            for(int i = c.start; i <= c.end; i++) {
                tmp += cntOfHamsters[i];
            }
            if(tmp != c.val) return ;
        }
            if(!ans.empty()) {

                int totalAns = 0, total = 0;

                for(int i = 0; i < ans.size(); i++) {
                    totalAns += ans[i];
                }

                for(int i = 1; i <= n; i++) {
                    total += cntOfHamsters[i];
                }

                if(totalAns < total) {
                    ans.clear();
                    for(int i = 1; i <= n; i++) {
                        ans.push_back(cntOfHamsters[i]);
                    }
                } else if(totalAns == total) {
                    for(int i = 0; i < ans.size(); i++) {
                        if(ans[i] > cntOfHamsters[i+1]) {
                            witchone = 1;
                            break;
                        } else if(ans[i] < cntOfHamsters[i+1]) {
                            witchone = 2;
                            break;
                        }
                    }

                    if(witchone == 1) {
                        ans.clear();
                        for(int i = 1; i <= n; i++) {
                            ans.push_back(cntOfHamsters[i]);
                        }
                    }
                }
            } else {
                for(int i = 1; i <= n; i++) {
                    ans.push_back(cntOfHamsters[i]);
                }
            }

        return ;
    }

    for(int i = 0; i <= x; i++) {
        cntOfHamsters[start] = i;
        dfs(start+1);
    }
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        v.clear();
        ans.clear();
        scanf("%d %d %d", &n, &x, &m);

        for(int i = 0 ; i < m; i++) {
            Condition c;
            int l, r, s;
            scanf("%d %d %d", &l, &r, &s);
            c.start = l;
            c.end = r;
            c.val = s;
            v.push_back(c);
        }

        dfs(1);

        printf("#%d ", tc);
        if(ans.size() == 0) {
            printf("-1");
        } else {
            for(int i = 0; i < ans.size(); i++) {
                printf("%d ", ans[i]);
            }
        }
        printf("\n");

    }


    return 0;
}