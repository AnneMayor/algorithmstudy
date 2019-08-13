#include <iostream>
#include <cstring>

using namespace std;
const int MAX = 1e6;

char lines[MAX];
int statusOfRooms[MAX];

int main() {

    int n;
    scanf("%d", &n);

    scanf("%s", lines);
    memset(statusOfRooms, 0, sizeof(statusOfRooms));

    for(int i = 0; i < n; i++) {
        switch (lines[i])
        {
            case 'L':
            for(int j = 0; j < 10; j++) {
                if(!statusOfRooms[j]) {
                    statusOfRooms[j] = 1;
                    break;
                }
            }
            break;

            case 'R':
            for(int j = 9; j >= 0; j--) {
                if(!statusOfRooms[j]) {
                    statusOfRooms[j] = 1;
                    break;
                }
            }
            break;

            default:
            statusOfRooms[lines[i]-'0'] = 0;
            break;
        }
    }

    for(int i = 0; i < 10; i++) {
        printf("%d", statusOfRooms[i]);
    }
    printf("\n");
    return 0;
}