#include <iostream>
#include <string.h>

using namespace std;
const int MAX = 1005;

int main()
{

    int t;
    scanf("%d", &t);

    for (int tc = 1; tc <= t; tc++)
    {

        char str[MAX];
        scanf("%s", str);

        int len = strlen(str);
        printf("%c%c\n", str[0], str[len-1]);
    }

    return 0;
}