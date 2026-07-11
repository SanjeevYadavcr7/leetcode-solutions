/* 
July 2026
Question Link: https://www.geeksforgeeks.org/problems/minimum-swaps/1
*/
class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        int n = arr.size();
        vector<int> sortedArr = arr;
        unordered_map<int, int> numIndexMap;
        
        // Maintaining sorted array to get original position of elements
        sort(sortedArr.begin(), sortedArr.end());
        
        for(int i = 0; i < n; i++) {
            numIndexMap[arr[i]] = i;
        }
        
        int minSwaps = 0;
        for(int i = 0; i < n; i++) {
            // if mismatch -> then we need to re-position element in original array
            if(arr[i] != sortedArr[i]) {
                minSwaps++;
                
                int sortedNumIdx = numIndexMap[sortedArr[i]];
                
                swap(arr[i], arr[sortedNumIdx]);

                // after swapping the elements update hashmap as well
                numIndexMap[arr[sortedNumIdx]] = sortedNumIdx;
                numIndexMap[arr[i]] = i;
            }
        }
        
        return minSwaps;
    }
};
