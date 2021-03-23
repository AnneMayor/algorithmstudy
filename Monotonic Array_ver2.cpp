#include <vector>

using namespace std;

bool isMonotonic(vector<int> array) {
    bool is_non_decreasing = true;
    bool is_non_increasing = true;

    int n = array.size();

    for(int i = 0; i < n-1; i++) {
        if(array[i] < array[i+1]) {
            is_non_decreasing = false;
        }

        if(array[i] > array[i+1]) {
            is_non_increasing = false;
        }
    }

    return is_non_increasing || is_non_decreasing;
}