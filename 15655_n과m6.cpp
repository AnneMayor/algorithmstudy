#include <iostream>
#include <vector>

using namespace std;

int n, m;
int nums[9];
bool isChecked[10005];
vector<int> ans;

void sort(int data[]) {

    // bubblesort

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

}

void solve(int len, int firstIdx) {

    if(len >= m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }

    for(int i = firstIdx; i < n; i++) {
        if(isChecked[i]) continue;
        isChecked[i] = true;
        ans.push_back(nums[i]);
        solve(len+1, i+1);
        isChecked[i] = false;
        ans.pop_back();
    }

}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    sort(nums);

    solve(0,0);

    return 0;

}