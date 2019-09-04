#include <iostream>
#include <stack>

using namespace std;
const int MAX = 105;

stack<int> start;
stack<int> last;

int number[MAX];

int main() {

    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &number[i]);
    }

    start.push(1);

    for(int i = 2; i <= n; i++) {

        for(int j = 0; j < number[i]; j++) {
            int point = start.top();
            start.pop();
            last.push(point);
        }
        start.push(i);

        while (!last.empty())
        {
            int point = last.top();
            last.pop();
            start.push(point);
        }
        
    }

    while (!start.empty())
    {
        int point = start.top();
        start.pop();
        last.push(point);
    }

    while (!last.empty())
    {
        printf("%d ", last.top());
        last.pop();
    }
    
    return 0;
}