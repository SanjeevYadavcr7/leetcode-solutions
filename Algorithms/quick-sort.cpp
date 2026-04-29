#include<iostream>
using namespace std;

/*
    Time Complexity: 
    1. Best = O(N.LogN)
    2. Average = O(N.LogN)
    3. Worst = O(N^2)

    Space Complexity: 
    1. Worst = O(N) // if tree is skewed means array is sorted and we are selecting last element as pivot
    2. Best or Average = O(LogN) // if tree is balanaced

*/

int getPivot(vector<int>& nums, int low, int high) {
    int pivot = nums[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[high]);
    return (i+1);
}

void quickSort(vector<int>& nums, int low, int high) {
    if(low < high) {
        int pivot = getPivot(nums, low, high);
        quickSort(nums, low, pivot - 1);
        quickSort(nums, pivot + 1, high);
    }
}