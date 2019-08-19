#include <iostream>
#include <list>

using namespace std;

list<int> li;

int main()
{
    cin.tie(NULL); cout.tie(NULL);

    for (int tc = 1; tc <= 10; tc++)
    {
        int n;
        cin >> n;

        li.clear();

        for (int i = 0; i < n; i++)
        {
            int password;
            cin >> password;

            li.push_back(password);
        }

        int m;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            char command;
            cin >> command;

            list<int>::iterator begin_itr = li.begin();
            // list<int>::iterator end_itr = li.end();

            switch (command)
            {
                int x, y;
            case 'I':
            cin >> x >> y;

            for(int i = 0; i < x; i++) begin_itr++;

            for(int i = 0; i < y; i++) {
                int nums;
                cin >> nums;
                li.insert(begin_itr, nums);
            }
            
                break;
            }
        }

        cout << "#" << tc << " ";
        for(int i = 0; i < 10; i++) {
            cout << li.front() << " ";
            li.pop_front();
        }
        cout << endl;

    }
    return 0;
}