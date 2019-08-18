//
//  2001_파리퇴치_D2.cpp
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
        
        int n, m;
        cin >> n >> m;
        
        int flies[100][100];
        
        for(int i = 0; i < 100; i++) {
            for(int j = 0; j < 100; j++) {
                flies[i][j] = 0;
            }
        }
        
        for(int i = 20; i < n+20; i++) {
            for(int j = 20; j < n+20; j++) {
                cin >> flies[i][j];
            }
        }
        
        int max = -1;
        
        for(int  i = 20; i < n+20; i++) {
            for(int j = 20; j < n+20; j++) {
                
                int temp = 0;
                for(int x = i; x < i+m; x++) {
                    for(int y = j; y < j+m; y++) {
                        temp += flies[x][y];
                    }
                }
                
                if(max < temp) {
                    max = temp;
                }
                
            }
        }
        
        cout << "#" << t << " " << max << endl;
        
    }
    
    return 0;
}
