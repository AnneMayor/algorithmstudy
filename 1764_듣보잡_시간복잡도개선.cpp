#include <iostream>
#include <string>
#include <cstring>
#include <set>

using namespace std;

struct Trie
{

    bool end[25];
    bool exist[25];
    Trie *next[25];

    Trie()
    {
        memset(end, 0, sizeof(end));
        memset(exist, 0, sizeof(exist));
        memset(next, 0, sizeof(next));
    }
};

Trie trie;
set<string> ans;

void trie_push(string name)
{

    Trie *tr = &trie;
    int lenOfName = name.length();
    for (int i = 0; i < lenOfName; i++)
    {
        int x = name[i] - 'a';
        tr->exist[x] = 1;

        if (i == lenOfName - 1)
        {
            tr->end[x] = 1;
        }
        else
        {
            if (!tr->next[x])
                tr->next[x] = new Trie();
            tr = tr->next[x];
        }
    }

    return;
}

bool trie_search(string name)
{
    Trie *tr = &trie;
    int lenOfName = name.length();
    for (int i = 0; i < lenOfName; i++)
    {
        int x = name[i] - 'a';
        if (!tr->exist[x])
            return false;
        if (i == lenOfName - 1)
        {
            if (tr->end[x])
                return true;
            else
                return false;
        }
        else
        {
            if (!tr->next[x])
                return false;
            tr = tr->next[x];
        }
    }

    return false;
}

int main()
{

    ios::sync_with_stdio(false);
    int n, m;
    string name;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> name;
        trie_push(name);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> name;
        if (trie_search(name))
        {
            ans.insert(name);
        }
    }

    cout << ans.size() << endl;

    if (ans.size() > 0)
    {

        for (auto n : ans)
        {
            cout << n << endl;
        }
    }

    return 0;
}