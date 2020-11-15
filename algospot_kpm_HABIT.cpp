#include <bits/stdc++.h>

using namespace std;

struct Comparator {
    int t;
    const vector<int> & group;

    Comparator(const vector<int> & g, int t1) : group(g), t(t1) {}

    bool operator() (int a, int b) {
        if(group[a] != group[b]) return group[a] < group[b];
        return group[a+t] < group[b+t];
    }

};

vector<int> getSuffixArray(const string & s) {
    int t = 1;
    int n = s.length();

    vector<int> group(n+1);
    for(int i = 0; i < n; i++) {
        group[i] = s[i];
    }
    group[n] = -1;

    vector<int> perm(n);
    for(int i = 0; i < n; i++) {
        perm[i] = i;
    }

    while (t < n)
    {
        Comparator compare(group, t);
        sort(perm.begin(), perm.end(), compare);

        t *= 2;
        if(t >= n) break;

        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for(int i = 1; i < n; i++) {
            if(compare(perm[i-1], perm[i])) {
                newGroup[perm[i]] = newGroup[perm[i-1]]+1;
            } else {
                newGroup[perm[i]] = newGroup[perm[i-1]];
            }
        }

        group = newGroup;
    }
    
    return perm;
}

int commonPreffix(const string & s, int i, int j) {
    int k = 0;
    while (i < s.length() && j < s.length() && s[i] == s[j])
    {
        i++, j++, k++;
    }

    return k;
}

int main(void) {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    vector<int> preffix;
    for(int t = 1; t <= T; t++) {
        int k;
        cin >> k;
        string speech;
        cin >> speech;

        preffix.clear();
        preffix = getSuffixArray(speech);

        int result = 0;
        for(int i = 0; i + k <= speech.length(); i++) {
            result = max(result, commonPreffix(speech, preffix[i], preffix[i+k-1]));
        }

        printf("%d\n", result);
    }

    return 0;
}