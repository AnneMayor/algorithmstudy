#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int ALPHABET = 26;

int toNumber(char ch) {
    return ch - 'A';
}

struct TrieNode
{
    TrieNode *children[ALPHABET];
    int terminal;
    int first;

    TrieNode():terminal(-1), first(-1) {
        memset(children, 0, sizeof(children));
    }

    ~TrieNode() {
        for(int i = 0; i < ALPHABET; i++) {
            if(children[i])
                delete(children[i]);
        }
    }

    void insert(const char* key, int id) {
        if(first==-1) first = id;
        if(*key == 0) terminal = id;
        else {
            int next = toNumber(*key);
            if(children[next] == NULL) {
                children[next] = new TrieNode();
            }
            children[next]->insert(key+1, id);
        }
    }

    TrieNode* find(const char* word) {
        if(*word == 0) return this;
        int next = toNumber(*word);
        if(children[next] == NULL) return NULL;
        return children[next]->find(word+1);
    }

    int type(const char * key, int id) {
        if(*key == 0) return 0;
        if(first==id) return 1;
        int next = toNumber(*key);
        return 1+children[next]->type(key+1, id);
    }
};

int countKeys(TrieNode * trie, const char* word) {
    TrieNode* node = trie->find(word);
    if(node == NULL || node->terminal == -1) return strlen(word);
    return trie->type(word, node->terminal);
}

TrieNode* readInput(int numOfWords) {
    vector<pair<int, string> > inputs;
    char str[11];
    int priority;
    for(int i = 0; i < numOfWords; i++) {
        scanf("%s %d", str, &priority);
        inputs.push_back(make_pair(-priority, str));
    }

    sort(inputs.begin(), inputs.end());
    TrieNode* trie = new TrieNode();
    for(int i = 0; i < numOfWords; i++) {
        trie->insert(inputs[i].second.c_str(), i);
    }
    trie->first = -1;
    return trie;
}

int main() {

    int T;
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        int n, m;
        scanf("%d %d", &n, &m);
        int ans = m-1;
        TrieNode* trie = readInput(n);
        char words[11];
        for(int i = 0 ; i < m; i++) {
            scanf("%s", words);
            ans += countKeys(trie, words);
        }
        printf("%d\n", ans);
    } 

    return 0;
}