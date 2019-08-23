#include <iostream>
#include <list>

using namespace std;

list<int> numList;

int main() {

    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    scanf("%d %d", &n, &k);

    for(int i = 1; i <= n; i++) {
        numList.push_back(i);
    }

    list<int>::iterator itr = numList.begin();

    cout << "<";
    while(numList.size() > 1)
    {
        for(int j = 0; j < k-1; j++) {
            itr++;
            if(itr == numList.end()) itr = numList.begin();
        }

        cout << (*itr) << ", ";
        numList.erase(itr++);
        if(itr == numList.end()) itr = numList.begin();
    }
    cout << (*itr) << ">" << endl;
    


    return 0;
}