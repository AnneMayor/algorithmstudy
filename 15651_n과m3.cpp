//
//  15651_n과m3.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 23/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> nums;

void solve(int len) {
    
    if(len >= m) {
        for(int num : nums) {
            printf("%d ", num);
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
