//
//  Sieve_Of_Eratosthenes.cpp
//  codingtest4mycareer
//
//  Created by DHL on 20/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    int n;
    cin.tie(0);
    cin >> n;
    int nums[n+1];
    
    // 초기화
    for(int i = 0; i <= n; i++) {
        nums[i] = 1;
    }
    
    // 에라토스테네스의 체로  1~n까지의 수 중 소수 구하기
    
    nums[1] = 0;
    int num = 2;
    while(num <= n) {
        for(int i = 2; i <= sqrt(num); i++) {
            if(nums[num] == 0) {
                continue;
            } else {
                if(num != i && num % i == 0) {
                    nums[num] = 0;
                }
            }
        }
        num++;
    }
    
    for(int i = 1; i <= n; i++) {
        if(nums[i] != 0) {
            cout << i << endl;
        }
    }
    
    return 0;
}
