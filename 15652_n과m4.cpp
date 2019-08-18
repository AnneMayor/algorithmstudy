//
//  15652_n과m4.cpp
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
vector<int> nums;

void solve(int len) {
    
    if(nums.size() > 1) {
        for(int i = 0; i < nums.size()-1; i++) {
            if(nums[i] > nums[i+1]) {
                return;
            }
        }
    }
    
    if(len >= m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        nums.push_back(i);
        solve(len+1);
        nums.pop_back();
    }
    
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    solve(0);
    
    return 0;
    
}
