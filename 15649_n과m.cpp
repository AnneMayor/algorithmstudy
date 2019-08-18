//
//  15649_n과m.cpp
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

void findAnswer(int cnt) {
    
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
        findAnswer(cnt+1);
        isVisited[i] = false;
        num.pop_back();
    }
    
}

int main() {
    
    cin.tie(0);
    cout.tie(0);
    scanf("%d %d", &n, &m);
    
    findAnswer(0);
    
    return 0;
}

