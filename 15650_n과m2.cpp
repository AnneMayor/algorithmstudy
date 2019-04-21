//
//  15650_n과m2.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 21/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> num;
bool isVisited[10];

void solve(int cnt) {
    
    if(num.size() > 1) {
        for(int i = 0 ; i < num.size()-1; i++) {
            if(num[i] > num[i+1]) {
                return;
            }
        }
    }
    
    if(cnt == m) {
        for(int i = 0; i < m; i++) {
            printf("%d ", num[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i = 1; i <= n; i++) {
        if(isVisited[i]) continue;
        isVisited[i] = true;
        num.push_back(i);
        solve(cnt+1);
        isVisited[i] = false;
        num.pop_back();
    }
    
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    solve(0);
    
    return 0;
    
}
