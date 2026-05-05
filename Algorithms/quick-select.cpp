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

int partition(vector<int>& nums, int beg, int end) {
    int pivot = nums[end];
    int i = beg - 1;
    for(int j = beg; j < end; j++) {
        if(nums[j] <= pivot) {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i+1], nums[end]);
    return (i+1);
}

int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pivotIdx = partition(arr, low, high);

        cout << "pivotIdx = " << pivotIdx << " | k = " << arr.size() - k << " | arr[pivotIdx] = " << arr[pivotIdx] << endl;
        if (pivotIdx == arr.size() - k) return arr[pivotIdx];
        else if(pivotIdx < arr.size() - k) return quickSelect(arr, pivotIdx + 1, high, k);
        else return quickSelect(arr, low, pivotIdx - 1, k);
    }
    return -1;
}

int findKthLargest(vector<int>& nums, int k) {
    int beg = 0, end = nums.size() - 1;
    return quickSelect(nums, beg, end, k);
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int kthLargestElement = findKthLargest(arr, k);
    cout << kthLargestElement << endl;

    return 0;
}