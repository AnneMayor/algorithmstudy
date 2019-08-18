//
//  2007_패턴마디의길이_D2.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 25/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    
    int T;
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    for(int t = 1; t <= T; t++) {
        string s;
        cin >> s;
        
        int ans = 0;
        string part;
        int len = 1;
        
        part += s.at(0);
        
        for(int i = 1; i < s.length(); i++) {
            if(part == s.substr(i, len)) {
                break;
            } else {
                len++;
                part += s.at(i);
            }
        }
        
        cout << "#" << t << " " << len << endl;
 
    }
    
    return 0;
}
