//
//  1926_간단한369게임_D2.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 25/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>

using namespace std;

void printClap(int num) {
    
    int cnt = 0;
    while(num > 0) {
        if(num % 10 == 3 || num % 10 == 6 || num % 10 == 9) {
            cnt++;
        }
        num /= 10;
    }
    
    for(int i = 0; i < cnt; i++) {
        cout << "-";
    }
    cout << " ";
    
}

int main() {
    
    int n;
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        int num = i;
        while(true) {
            if(num % 10 == 3 || num % 10 == 6 || num % 10 == 9) {
                printClap(i);
                break;
            } else {
                if(num == 0) {
                    cout << i << " ";
                    break;
                }
                num /= 10;
            }
        }
    }
    
    cout << endl;
    
    
    return 0;
}
