//
//  mergeSort_구현.cpp
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

void merge(int nums[], int leftStart, int leftEnd, int rightStart, int rightEnd) {
    
    int temp[n];
    int index = 0;
    
    int l = leftStart;
    int r = rightStart;
    
    while(l <= leftEnd && r <= rightEnd) {
        if(nums[l] >= nums[r]) {
            temp[index++] = nums[r];
            r++;
        } else {
            temp[index++] = nums[l];
            l++;
        }
    }
    
    if(l > leftEnd) {
        for(int i = r; i <= rightEnd; i++) {
            temp[index++] = nums[i];
        }
    } else if(r > rightEnd) {
        for(int i = l; i <= leftEnd; i++) {
            temp[index++] = nums[i];
        }
    }
    
    for(int i = leftStart; i <= rightEnd; i++) {
        nums[i] = temp[i-leftStart];
    }
}

void mergeSort(int nums[], int start, int end) {
    
    if(start >= end) {
        return;
    }
    
    int mid = (start + end) / 2;
    // 왼쪽정렬
    mergeSort(nums, start, mid);
    // 오른쪽 정렬
    mergeSort(nums, mid+1, end);
    // 병합
    merge(nums, start, mid, mid+1, end);
    
}

int main() {
    
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }
    
    mergeSort(data, 0, n-1);
    
    for(int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    
    printf("\n");
    
    return 0;
}
