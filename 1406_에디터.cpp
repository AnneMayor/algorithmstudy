#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {

    cin.tie(NULL); cout.tie(NULL);

    string st;
    int n;

    cin >> st;
    cin >> n;

    list<char> str(st.begin(), st.end());
    auto it = str.end();

    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;

        switch (c)
        {
        case 'L':
        if(it != str.begin()) it--;
            break;
        
        case 'B':
        if(it != str.begin()) {
            --it;
            it = str.erase(it);
        }
            break;

        case 'D':
        if(it != str.end()) it++;
            break;

        case 'P':
        char ch;
        cin >> ch;
        str.insert(it, ch);
            break;
        }
    }

    for(auto &itr:str) {
        cout << itr;
    }
    cout << endl;

    return 0;
}