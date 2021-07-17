#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAX = 30;

int adj[MAX][MAX];
int seen[MAX];

void makeGraph(vector<string> & words) {

    for(int i = 1; i < words.size(); i++) {
        string prev = words[i-1];
        string next = words[i];

        int len = min(prev.length(), next.length());
        for(int j = 0; j < len; j++) {
            if(prev[j] != next[j]) {
                int a = prev[j] - 'a';
                int b = next[j] - 'a';
                adj[a][b] = 1;
                break;
            }
            
        }
    }

    return ;
}

void dfs(int here, vector<int> & order) {
    seen[here] = 1;
    for(int there = 0; there < 26; there++) {
        if(adj[here][there] && !seen[there]) dfs(there, order);
    }
    order.push_back(here);
}

vector<int> topologicalSort() {
    vector<int> order;
    for(int i = 0; i < 26; i++) {
        if(!seen[i]) dfs(i, order);
    }

    reverse(order.begin(), order.end());

    for(int i = 0; i < 26; i++) {
        for(int j = i+1; j < 26; j++) {
            if(adj[order[j]][order[i]]) return vector<int>();
        }
    }

    return order;
}

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for(int tc = 1; tc <= T; tc++) {
        int n;
        cin >> n;
        memset(seen, 0, sizeof(seen));
        memset(adj, 0, sizeof(adj));

        vector<string> words;
        for(int i = 0; i < n; i++) {
            string word;
            cin >> word;
            words.push_back(word);
        }

        makeGraph(words);

        vector<int> res = topologicalSort();
        
        string ans = "";
        for(auto num : res) {
            ans += num + 'a';
        }

        if(ans == "") {
            cout << "INVALID HYPOTHESIS" << endl;
        }
        else cout << ans << endl;
    }


    return 0;
}