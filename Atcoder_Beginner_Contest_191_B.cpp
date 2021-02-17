#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    ios::sync_with_stdio(false);
    cout.tie(NULL);

    int n, x;
    scanf("%d %d", &n, &x);

    vector<int> numList;
    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        numList.push_back(num);
    }

    for(int i = 0; i < n; i++) {
        if(numList[i] == x) numList[i] = 0;
    }

    for(auto num : numList) {
        if(num > 0) printf("%d ", num);
    }
    printf("\n");

    return 0;
}