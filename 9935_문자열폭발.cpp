#include <iostream>
#include <string>
#include <deque>

using namespace std;
const int MAX = 1000000;

deque<char> str;

int main() {

    cin.tie(NULL); cout.tie(NULL);

    string text, bomb;
    cin >> text >> bomb;

    int left = 0, right = text.length()-1;

    while (left <= right) {
        bool flag = false;
        str.push_front(text[right--]);
        if(str.size() >= bomb.length()) {
            flag = true;
            for(int i = 0; i < bomb.length(); i++) {
                if(str[i] != bomb[i]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                for(int i = 0; i < bomb.length(); i++) {
                    str.pop_front();
                }
            }
        }
    }

    string result = "";
    for(int i = 0; i < str.size(); i++) {
        result += str[i];
    }

    while(result.find(bomb) < MAX) {
        result.replace(result.find(bomb), bomb.length(), "");
    }

    if(result == "") {
        cout << "FRULA" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}