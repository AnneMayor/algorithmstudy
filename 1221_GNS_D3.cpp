#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
map<int, string> ht;
vector<int> vs;

int main() {

    ht.insert(make_pair(0, "ZRO"));
    ht.insert(make_pair(1, "ONE"));
    ht.insert(make_pair(2, "TWO"));
    ht.insert(make_pair(3, "THR"));
    ht.insert(make_pair(4, "FOR"));
    ht.insert(make_pair(5, "FIV"));
    ht.insert(make_pair(6, "SIX"));
    ht.insert(make_pair(7, "SVN"));
    ht.insert(make_pair(8, "EGT"));
    ht.insert(make_pair(9, "NIN"));

    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {

        vs.clear();

        string st;
        int n;
        cin >> st >> n;

        for(int i = 0; i < n; i++) {

            string num;
            cin >> num;

            int tmp;
            if(num == "ZRO") {
                tmp = 0;
            } else if(num == "ONE") {
                tmp = 1;
            } else if(num == "TWO") {
                tmp = 2;
            } else if(num == "THR") {
                tmp = 3;
            } else if(num == "FOR") {
                tmp = 4;
            } else if(num == "FIV") {
                tmp = 5;
            } else if(num == "SIX") {
                tmp = 6;
            } else if(num == "SVN") {
                tmp = 7;
            } else if(num == "EGT") {
                tmp = 8;
            } else if(num == "NIN"){
                tmp = 9;
            }

            vs.push_back(tmp);
        }

        sort(vs.begin(), vs.end());

        cout << st << " ";
        for(int i = 0; i < n; i++) {
            cout << ht.find(vs[i])->second << " ";
        }
        cout << endl;
    }

    return 0;
}