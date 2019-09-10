
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string answer;
vector<string> result(2);

bool isPerfectString(string s) {
    stack<char> st;
    
    int len = s.length();

    for(int i = 0; i < len; i++) {
        char c = s[i];
        if(c == '(') {
            st.push(c);
        } else {
            if(!st.empty()) {
                st.pop();
            } else return false;
        }
    }

    return st.empty();
}

vector<string> getBalancedString(string s) {

    result.clear();
    string u = "", v = "";

    int len = s.length();

    int cntOfleft = 0;
    int cntOfRight = 0;

    int point = -1;

    for(int i = 0; i < len; i++) {
        char c = s[i];
        if(c == '(') {
            cntOfleft++;
        } else {
            cntOfRight++;
        }

        if(cntOfleft == cntOfRight) {
            point = i;
            break;   
        }

    }

    u = s.substr(0, point+1);
    v = s.substr(point+1, len-point);

    result.push_back(u);
    result.push_back(v);

    return result;
}

string findPerfectString(string s) {

    if(s == "") return s;

    vector<string> sList = getBalancedString(s);

    string u = sList[0];
    string v = sList[1];

    // cout << "u: " << u << " v: " << v << endl;

    if(isPerfectString(u)) {
        return u + findPerfectString(v);
    } else {

        string ret = "";
        for(int i = 1; i < u.length()-1; i++) {
            if(u[i] == '(') {
                ret += ")";
            } else {
                ret += "(";
            }
        }

        // cout << "ret: " << ret << endl;

        return "(" + findPerfectString(v) + ")" + ret;
    }

    return s;

}

string solution(string p) {

    answer = "";

    if(isPerfectString(p)) {
        answer = p;
    } else {
        answer = findPerfectString(p);
    }
    
    return answer;
}