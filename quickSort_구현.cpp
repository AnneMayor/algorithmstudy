//
//  quickSort_구현.cpp
//  algorithmstudy
//  codingtest4mycareer
//
//  Created by DHL on 22/04/2019.
//  Copyright © 2019 DHL. All rights reserved.
//

#include <iostream>

using namespace std;

const int MAX = 100005;

int n;
int data[MAX];
int leftArr[MAX], rightArr[MAX];

int getLeftArray(int pivot, int nums[], int start, int end, int result[]) {

    int idx = 0;

    for(int i = start; i <= end; i++) {
        if(nums[i] <= pivot) {
            result[idx++] = nums[i];
        }
    }
    
    return idx;
    
}

int getRightArray(int pivot, int nums[], int start, int end, int result[]) {
    
    int idx = 0;
    
    for(int i = start; i <= end; i++) {
        if(nums[i] > pivot) {
            result[idx++] = nums[i];
        }
    }
    
    return idx;
    
}

void quickSort(int nums[], int start, int end) {
    
    if(start >= end) {
        return;
    }
    
    int pivot = nums[start];
    
    // 왼쪽 배열 얻기
    int cntOfLeft = getLeftArray(pivot, nums, start+1, end, leftArr);
    
    // 오른쪽 배열 얻기
    int cntOfRight = getRightArray(pivot, nums, start+1, end, rightArr);
    
    // pivot 위치 넣기
    for(int i = start; i < start + cntOfLeft; i++) {
        nums[i] = leftArr[i-start];
    }
    
    nums[start+cntOfLeft] = pivot;
    
    for(int i = 0; i < cntOfRight; i++) {
        nums[start+cntOfLeft+1+i] = rightArr[i];
    }
    
    // 왼쪽 퀵정렬
    quickSort(nums, start, start+cntOfLeft-1);
    
    // 오른쪽 퀵정렬
    quickSort(nums, start+cntOfLeft+1, end);
    
}

int main() {

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    
    quickSort(data, 0, n-1);
    
    for(int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }

    return 0;
}
