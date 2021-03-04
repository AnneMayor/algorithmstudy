#include <bits/stdc++.h>

using namespace std;

const int MODULO = 10000019;

void getCombination(vector<vector<long long> > & arr, int row) {
    arr[0][0] = 1;
    for(int i = 1; i <= row; i++) {
        for(int j = 0; j <= row; j++) {
            if(i == j || j == 0) arr[i][j] = 1;
            else {
                arr[i][j] = (arr[i-1][j] + arr[i-1][j-1]) % MODULO;
            } 
        }
    }
    return ;
}

void getOneCountArr(vector<vector<int>> a, vector<int> & oneArr, int row, int col) {
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++) {
            oneArr[i] += a[j][i];
        }
    }
    return ;
}

int solution(vector<vector<int> > a) {

    int row = a.size();
    int col = a[0].size();

    vector<vector<long long> > nCr(row+1, vector<long long>(row+1, 0));
    getCombination(nCr, row);

    vector<int> oneCnt(col+1);
    getOneCountArr(a, oneCnt, row, col);

    vector<vector<long long> > dp(col + 1, vector<long long>(row+1, 0));

    dp[1][row-oneCnt[0]] = nCr[row][row-oneCnt[0]];
    for(int i = 1 ; i < col; i++) {
        
        int numOfOne = oneCnt[i];
        for(int evenNum = 0; evenNum <= row; evenNum++) {
            for(int k = 0; k <= numOfOne; k++) {
                if(evenNum < k) continue;
                int availableEven = evenNum + numOfOne - 2*k;
                if(availableEven > row) continue;
                long long result = (nCr[row - evenNum][numOfOne-k]*nCr[evenNum][k]) % MODULO;
                dp[i+1][availableEven] += result * dp[i][evenNum];
                dp[i+1][availableEven] %= MODULO;
            }
        }
    }
    
    return dp[col][row];
}