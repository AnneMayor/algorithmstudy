#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
const int MAX = 1e6+5;

int failure[MAX];

void getFailureArr(char p []) {
    
    int pLen = strlen(p);
    pLen--;
    int j = 0;
    for(int i = 1; i < pLen; i++) {
        while (j > 0 && p[i] != p[j])
        {
            j = failure[j-1];
        }

        if(p[i] == p[j]) failure[i] = ++j;
    }
    
    return ;

}

int main() {

    char t[MAX], p[MAX];
    fgets(t, MAX, stdin);
    fgets(p, MAX, stdin);

    int tLen = strlen(t);
    int pLen = strlen(p);

    tLen--, pLen--;

    memset(failure, 0, sizeof(failure));

    getFailureArr(p);

    vector<int> idxList;

    int j = 0;
    for(int i = 0; i < tLen; i++) {
        while (j > 0 && t[i] != p[j])
        {
            j = failure[j-1];
        }
        if(t[i] == p[j]) {
            if(j == pLen-1) {
                idxList.push_back(i-pLen+2);
                j = failure[j];
            } else ++j;
        }
    }

    printf("%lu\n", idxList.size());
    for(int & idx : idxList) printf("%d\n", idx);

    return 0;
}