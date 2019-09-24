#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> ansList;
    for(int i = 1; i <= n; i++) {
        if(n%i == 0) {
            ansList.push_back(i);
        }
    }
    
    int ans = 0;
    sort(ansList.begin(), ansList.end());

    if(ansList.size() < k) {
        printf("%d\n", ans);
        return 0;
    }

    ans = ansList[k-1];
    printf("%d\n", ans);

    return 0;
}