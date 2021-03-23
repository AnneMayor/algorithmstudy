#include <vector>

using namespace std;

// O(n) Time | O(1) Space
bool isMonotonic(vector<int> array) {

    bool isMonotonic = true;
    int pattern = -1; // 0: decrease, 1: increase

    int n = array.size();
    if(n <= 1) return isMonotonic;

    for(int i = 0; i < n-1; i++) {
        if(array[i] < array[i+1]) {
            pattern = 1;
            break;
        } else if(array[i] > array[i+1]) {
            pattern = 0;
            break;
        }
    }

    if(pattern == -1) return isMonotonic;
    
    switch (pattern)
    {
    case 0:
    for(int i = 0; i < n-1; i++) {
        if(array[i] < array[i+1]) {
            isMonotonic = false;
            break;
        }
    }
        break;
    
    case 1:
    for(int i = 0; i < n-1; i++) {
        if(array[i] > array[i+1]) {
            isMonotonic = false;
            break;
        }
    }
        break;
    }

    return isMonotonic;
}
