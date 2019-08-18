//
//  2071_평균값구하기_D1.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 21/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int T;
    cin.tie(0);
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        double nums[10];
        double total = 0;
        double ans = 0;
        
        for(int i = 0; i < 10; i++) {
            cin >> nums[i];
            total += nums[i];
        }
        
        ans = total / 10;
        
        ans = round(ans);
        
        cout << "#" << t << " " << ans << endl;
        
    }
    
    return 0;
}
