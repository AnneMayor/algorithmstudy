#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 55;

vector<string> strList;

bool comp(string &s1, string &s2) {
    if(s1.length() != s2.length()) {
        return s1.length() < s2.length();
    } else {
        int sumS1 = 0, sumS2 = 0;
        int lenS1 = s1.length();
        for(int i = 0; i < lenS1; i++) {
            if(s1[i]-'0' >= 0 && s1[i]-'0' < 10) sumS1 += s1[i]-'0';
        }

        int lenS2 = s2.length();
        for(int i = 0; i < lenS2; i++) {
            if(s2[i]-'0' >= 0 && s2[i]-'0' < 10) sumS2 += s2[i]-'0';
        }

        if (sumS1 != sumS2)
        {
            return sumS1 < sumS2;
        }
        
    }

    return s1 < s2;
}

int main() {

    cin.tie(NULL);
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        strList.push_back(s);
    }

    sort(strList.begin(), strList.end(), comp);

    for(int i = 0; i < n; i++) {
        printf("%s\n", strList[i].c_str());
    }

    return 0;
}