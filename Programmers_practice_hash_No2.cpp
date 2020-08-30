#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 100;

bool isPhoneLength[MAX];

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> phonePrefix;
    memset(isPhoneLength, false, sizeof(isPhoneLength));
    int minLen = 100;

    sort(phone_book.begin(), phone_book.end());

    for(auto number : phone_book) {
        int len = number.length();
        isPhoneLength[len] = true;
        if(minLen > len) minLen = len;
    }

    for(auto phone : phone_book) {
        int len = phone.length();   
        
        for(int i = minLen; i <= len; i++) {
            if(isPhoneLength[i]) {
                string prefix = phone.substr(0, i);
                if(phonePrefix.find(prefix) != phonePrefix.end()) {
                    answer = false;
                    break;
                }
                if(i == len) 
                {
                    phonePrefix.insert(prefix);
                }
            }
        }
        if(!answer) break;
    }
    
    return answer;
}