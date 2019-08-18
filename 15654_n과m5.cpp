//
//  15654_n과m5.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 25/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> ans;
int nums[8];
bool isChecked[10001];

void solve(int len) {
    
    if(len >= m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i = 0; i < n; i++) {
        if(isChecked[nums[i]]) continue;
        isChecked[nums[i]] = true;
        ans.push_back(nums[i]);
        solve(len+1);
        isChecked[nums[i]] = false;
        ans.pop_back();
    }
    
}

void sort(int nums[]) {
    for(int i = 0; i < n; i++) {
        int min = 1000000;
        int idx = -1;
        for(int j = i; j < n; j++) {
            if(min > nums[j]) {
                min = nums[j];
                idx = j;
            }
        }
        int temp = nums[i];
        nums[i] = min;
        nums[idx] = temp;
    }
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    // 정렬
    sort(nums);
    
    solve(0);
    
    return 0;
}
