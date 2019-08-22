#include <iostream>
#include <string>
#include <queue>

using namespace std;
queue<int> q;

int main() {

    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if(command == "push") {
            int num;
            cin >> num;
            q.push(num);
        } else if(command == "pop") {
            if(q.empty()) {
                cout << "-1" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        } else if(command == "front") {
            if(q.empty()) {
                cout << "-1" << endl;
            } else {
                cout << q.front() << endl;
            }
        } else if(command == "size") {
            cout << q.size() << endl;
        } else if(command == "empty") {
            if(q.empty()) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if(command == "back") {
            if(q.empty()) {
                cout << "-1" << endl;
            } else {
                cout << q.back() << endl;
            }
        }
    }

    return 0;
}