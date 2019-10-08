#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 1e5+5;

vector<vector<int> > treeNode(MAX);
int parent[MAX];

void findParent(int num) {

    for(int i = 0; i < treeNode[num].size(); i++) {
        if(parent[treeNode[num][i]] == -1) {
            parent[treeNode[num][i]] = num;
            findParent(treeNode[num][i]);
        }
    }

    return ;
}


int main() {

    int n;
    scanf("%d", &n);

    memset(parent, -1, sizeof(parent));
    parent[1] = 1;

    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        treeNode[a].push_back(b);
        treeNode[b].push_back(a);
    }

    findParent(1);
    
    for(int i = 2; i <= n; i++) {
        printf("%d\n", parent[i]);
    }

    return 0;
}