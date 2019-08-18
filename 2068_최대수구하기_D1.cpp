//
//  2068_최대수구하기_D1.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 21/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int T;
    cin.tie(0);
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        
        int nums[10];
        int max = -1000;
        
        for(int i = 0; i < 10; i++) {
            cin >> nums[i];
            if(max < nums[i]) {
                max = nums[i];
            }
        }
        
        cout << "#" << t << " " << max << endl;
        
    }
    
    return 0;
}
