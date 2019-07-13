#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;
const int MAX = 35;

char str[MAX];
stack<string> s;

int stringToInt(string s) {

    int len = s.length();
    int result = 0;
    for(int i = 0; i < len; i++) {
        result += (s.at(i)-'0')*pow(10, (len-1-i));
    }
    return result;
}

bool isGoodStr(char str[], int len) {
    int flag = false;

    for(int i = 0; i < len; i++) {
        if(str[i] == '(' || str[i] == '[') {
            string sign = "";
            sign += str[i];
            s.push(sign);
        } else if(str[i] == ']' || str[i] == ')') {
            if(s.empty()) {
                return flag;
            } else if(str[i] == ']') {
                if(s.top() == "[") s.pop();
                else return flag;
            } else if(str[i] == ')') {
                if(s.top() == "(") s.pop();
                else return flag;
            }
        }
    }
    
    if(s.size() == 0) flag = true;

    return flag;
}

int main() {

    scanf("%s", str);

    int len = strlen(str);

    if(isGoodStr(str, len)) {

        for(int i = 0; i < len; i++) {
            if(str[i] == '(' || str[i] == '[') {
                    string sign = "";
                    sign += str[i];
                    s.push(sign);
            } else if(str[i] == ']') {
                if(s.top() != "[") {
                    int tmp = 0;
                    while(s.top() != "[") {
                        tmp += stringToInt(s.top());
                        s.pop();
                    }
                    tmp *= 3;
                    s.pop();
                    string numS = to_string(tmp);
                    s.push(numS);
                } else {
                    s.pop();
                    s.push("3");
                }
            } else if(str[i] == ')') {
                if(s.top() != "(") {
                    int tmp = 0;
                    while(s.top() != "(") {
                        tmp += stringToInt(s.top());
                        s.pop();
                    }
                    tmp *= 2;
                    string numS = to_string(tmp);
                    s.pop();
                    s.push(numS);
                } else {
                    s.pop();
                    s.push("2");
                }
            }
        }

        int ans = 0;
        while(!s.empty()) {
            ans += stringToInt(s.top());
            s.pop();
        }

        printf("%d\n", ans);

    } else {
        printf("0\n");
    }

    return 0;
}