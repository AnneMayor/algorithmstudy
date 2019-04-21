//
//  2063_중간값찾기_D1.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 21/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int n;
    cin.tie(0);
    cin >> n;
    int nums[n];
    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 오름차순 정렬
    for(int i = 0; i < n; i++) {
        int min = 200;
        int idx = 0;
        for(int j = i; j < n; j++) {
            if(min > nums[j]) {
                min = nums[j];
                idx = j;
            }
        }
        int temp = nums[i];
        nums[i] = nums[idx];
        nums[idx] = temp;
    }
    
    ans = nums[n/2];
    
    cout << ans << endl;
    
    return 0;
}
