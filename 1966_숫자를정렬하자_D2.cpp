#include <iostream>

using namespace std;

void bubblesort(int data[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(data[j] > data[j+1]) {
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}

int main() {

    int T;
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    for(int t = 1; t <= T; t++) {

        int n;
        cin >> n;
        
        int nums[n];

        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        bubblesort(nums, n);

        cout << "#" << t << " ";

        for(int i = 0; i < n; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;

    }

    return 0;
}