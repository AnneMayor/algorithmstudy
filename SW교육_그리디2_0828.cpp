#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e5+5;

int meetingStart[MAX];
int meetingEnd[MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int start, end;
        scanf("%d %d", &start, &end);

        meetingStart[i] = start;
        meetingEnd[i] = end;
    }

    sort(meetingStart, meetingStart+n);
    sort(meetingEnd, meetingEnd+n);

    int idxStart = 0, idxEnd = 0;
    int cntOfRooms = 0;
    while(idxStart < n && idxEnd < n) {
        // cout << "idxStart: " << idxStart << " / idxEnd: " << idxEnd << endl;
        if(meetingStart[idxStart] < meetingEnd[idxEnd]) {
            cntOfRooms++;
            idxStart++;
        } else {
            idxStart++;
            idxEnd++;
        }
    }

    printf("%d\n", cntOfRooms);

    return 0;
}