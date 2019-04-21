//
//  2070_큰놈,작은놈,같은놈_D1.cpp
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
        
        int num1, num2;
        cin >> num1 >> num2;
        
        if(num1 > num2) {
            cout << "#" << t << " " << ">" << endl;
        } else if(num1 < num2) {
            cout << "#" << t << " " << "<" << endl;
        } else {
            cout << "#" << t << " " << "=" << endl;
        }
        
    }
    
    return 0;
}
