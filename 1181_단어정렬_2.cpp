#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 3e4;

set<string> wordsGroup;
vector<string> wordsList;
vector<int> wordLengthList;

bool checkWords[MAX];

int main() {

    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    scanf("%d", &n);

    memset(checkWords, 0, sizeof(checkWords));

    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        int len = word.length();
        if(wordsGroup.find(word) == wordsGroup.end()) {
            wordsGroup.insert(word);
            wordsList.push_back(word);
            wordLengthList.push_back(len);
        }
    }

    sort(wordsList.begin(), wordsList.end());
    sort(wordLengthList.begin(), wordLengthList.end());

    int numOfWords = wordsList.size();
    for(int i = 0; i < numOfWords; i++) {
        for(int j = 0; j < numOfWords; j++) {
            if(!checkWords[j] && wordLengthList[i] == wordsList[j].length()){
                checkWords[j] = 1;
                cout << wordsList[j] << endl;
            }
        }
    }

    return 0;
}