class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size();
        
        while (left + 1< right) {
            int mid = left + (right - left) / 2;
            if (mid == 0 || arr[mid - 1] < arr[mid]) left = mid;
            else right = mid;
        }
        return left;
    }
};