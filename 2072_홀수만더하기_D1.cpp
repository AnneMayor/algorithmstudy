//
//  2072_홀수만더하기_D1.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 20/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int T;
    // C++ 입력 성능개선(속도 올리기)
    // 빠른 입출력을 위해선 scanf,printf 활용 권장
    cin.tie(0);
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        int nums[10];
        int ans = 0;
        // 입력
        for(int i = 0; i < 10; i++) {
            cin >> nums[i];
        }
        
        // 홀수 비교
        for(int i = 0; i < 10; i++) {
            if(nums[i] % 2 != 0) {
                ans += nums[i];
            }
        }
        
        cout << "#" << t << " " << ans << endl;
        
    }
    
    return 0;
}
