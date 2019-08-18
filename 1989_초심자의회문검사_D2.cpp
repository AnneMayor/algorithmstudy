//
//  1989_초심자의회문검사_D2.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 27/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    bool flag = true;

    int len = s.length() / 2;
    int total = s.length();

    if(len % 2 == 0) {
        for(int i = 0; i <= len; i++) {
            if(s.at(i) != s.at(total-1-i)) {
                flag = false;
                return flag;
            }
        }
    } else {
        for(int i = 0; i < len; i++) {
            if(s.at(i) != s.at(total-1-i)) {
                flag = false;
                return flag;
            }
        }
    }

    return flag;
}

int main() {

    int T;
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    for(int t = 1; t <= T; t++) {
        
        string s;
        cin >> s;

        if(isPalindrome(s)) {
            cout << "#" << t << " 1" << endl;
        } else {
            cout << "#" << t << " 0" << endl;
        }

    }
    

    return 0;
}