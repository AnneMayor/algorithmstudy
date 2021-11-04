#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Train {
    int front = -1;
    int rear = -1;
};

vector<Train> trains;

void recursiveSearch(vector<int> & res, int start, int dir);

int main(void) {

    int n, q;
    scanf("%d %d", &n, &q);

    trains.resize(n+1);

    int printFlag = 0;

    while (q--)
    {
        int command;
        scanf("%d", &command);

        switch (command)
        {
        int x, y;
        case 1:    
            scanf("%d %d", &x, &y);
            trains[x].rear = y;
            trains[y].front = x;
            break;

        case 2:
            scanf("%d %d", &x, &y);
            trains[x].rear = -1;
            trains[y].front = -1;
            break;

        case 3:
            scanf("%d", &x);
            vector<int> res;
            recursiveSearch(res, trains[x].front, 1);
            if(!res.empty()) {
                reverse(res.begin(), res.end());
            }
            res.push_back(x);
            recursiveSearch(res, trains[x].rear, 2);

            printf("%d ", res.size());
            for(auto t : res) {
                printf("%d ", t);
            }
            printf("\n");

            break;
        }
    }

    return 0;
}

void recursiveSearch(vector<int> & res, int start, int dir) {

    if(start == -1) {
        return ;
    }

    res.push_back(start);

    if(dir == 1) {
        recursiveSearch(res, trains[start].front, dir);
    } else {
        recursiveSearch(res, trains[start].rear, dir);
    }
}
