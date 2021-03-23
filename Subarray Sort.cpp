#include <vector>

using namespace std;

bool isOutOfOrder(int num, vector<int> & array, int idx);
vector<int> subarraySort(vector<int> array);


// O(n) Time | O(1) Space
vector<int> subarraySort(vector<int> array) {

    int n = array.size();
    int startIdx = -1, endIdx = -1, finalStart = 0, finalEnd = n-1;
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for(int i = 0; i < n; i++) {
        int num = array[i];
        if(isOutOfOrder(num, array, i)) {
            if(smallest > num) smallest = num;
            if(largest < num) largest = num;
        }
    }

    if(smallest == INT_MAX && largest == INT_MIN) return {-1, -1};

    for(int i = 0; i < n; i++) {
        if(smallest >= array[i]) finalStart++;
        else break;        
    }

    for(int i = n-1; i >= 0; i--) {
        if(largest <= array[i]) finalEnd--;
        else break;
    }

    return {finalStart, finalEnd};
}

bool isOutOfOrder(int num, vector<int> & array, int idx) {
    int n = array.size();
    if(idx == 0) return num > array[idx+1];
    if(idx == n -1) return num < array[idx-1];
    return num < array[idx-1] || num > array[idx+1];
}
