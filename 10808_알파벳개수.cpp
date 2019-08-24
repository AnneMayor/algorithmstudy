#include <iostream>
#include <set>
#include <cstring>

using namespace std;
const int MAX = 105;

char str[MAX];

multiset<char> alpha;

int main() {

    scanf("%s", str);

    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        alpha.insert(str[i]);
    }

    for(int i = 0; i < 26; i++) {
        printf("%lu ", alpha.count('a'+i));
    }
    printf("\n");

    return 0;
}