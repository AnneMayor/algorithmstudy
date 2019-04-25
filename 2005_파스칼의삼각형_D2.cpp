//
//  2005_파스칼의삼각형_D2.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 25/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    
    int T;
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    for(int t = 1; t <= T; t++) {
        
        int n;
        cin >> n;
        
        int map[n][n];
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                map[i][j] = 0;
            }
        }
        
        for(int i = 0; i < n; i++) {
            map[i][0] = 1;
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= i; j++) {
                map[i][j] = map[i-1][j-1] + map[i-1][j];
            }
        }
        
        cout << "#" << t << endl;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(map[i][j] == 0) continue;
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        
        
    }
    
    return 0;
}
