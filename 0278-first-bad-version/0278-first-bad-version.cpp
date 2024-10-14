// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        int first_bad = -1;
        // f f f t t t t
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (isBadVersion(mid) == true){
                right =  mid - 1;
                first_bad = mid;
            } else {
                left = mid + 1;
            }
        }

        return first_bad;
    }
};