#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int n;
    scanf("%d", &n);

    vector<vector<int> > graphs(n+1);

    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graphs[a].push_back(b);
        graphs[b].push_back(a);
    }

    int cntOfCenter = 0;
    for(int i = 1; i <= n; i++) {
        int cntOfPair = graphs[i].size();
        if(cntOfPair > 1) cntOfCenter++;
    }

    if(cntOfCenter <= 1) printf("Yes\n");
    else printf("No\n");

    return 0;
}