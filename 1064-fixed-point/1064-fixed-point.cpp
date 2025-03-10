class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        // if arr[i] < i, we should move up
        // else if arr[i] > i, we should move down

        // else return 


        int left = 0, right = arr.size() - 1;

        int result = -1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] == mid)  {
                result = mid;
                right = mid -1;
            }
            else if (arr[mid] < mid) left = mid + 1;
            else right = mid -1; 
        }

        return result;
    }
};