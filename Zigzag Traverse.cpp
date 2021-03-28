#include <vector>

using namespace std;

int isOutOfRange(int row, int col, int height, int width);

vector<int> zigzagTraverse(vector<vector<int>> array) {
    vector<int> oneDimension;

    int height = array.size() - 1;
    int width = array[0].size() - 1;
    int row = 0, col = 0;
    int goingDown = 1;

    while (!isOutOfRange(row, col, height, width))
    {
        oneDimension.push_back(array[row][col]);
        if (goingDown)
        {
            if(col == 0 || row == height) {
                goingDown = 0;
                if(row == height) col++;
                else row++;
            } else {
                row++;
                col--;
            }
        } else {
            if(col == width || row == 0) {
                goingDown = 1;
                if(col == width) row++;
                else col++;
            } else {
                row--;
                col++;
            }
        }
        
    }
    
    return oneDimension;
}

int isOutOfRange(int row, int col, int height, int width) {
    return row < 0 || col < 0 || row > height || col > width;
}