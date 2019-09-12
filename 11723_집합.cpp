#include <iostream>

using namespace std;
const int MAX = 30;

int main()
{

    int n;
    cin.tie(NULL);

    scanf("%d\n", &n);
    int ans = 0;

    char command[MAX];

    for (int i = 0; i < n; i++)
    {

        scanf("%s", command);

        int num;
        switch (command[1])
        {
        case 'd':
            scanf("%d", &num);
            ans |= (1 << num);
            break;

        case 'h':
            scanf("%d", &num);
            printf("%d\n", (ans & (1 << num)) ? 1 : 0);
            break;

        case 'e':
            scanf("%d", &num);
            ans &= ~(1 << num);
            break;

        case 'l':
            ans = ~(0);
            break;

        case 'm':
            ans = 0;
            break;

        case 'o':
            scanf("%d", &num);
            ans ^= (1 << num);
            break;
        }
    }

    return 0;
}