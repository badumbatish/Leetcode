class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.size() == 1) {
            if (citations.front() == 0) return 0;
            return 1;
        }
        int64_t left = 0, right = citations.size();

        while (left < right) {
            int64_t mid = left + (right - left) / 2;
            printf("%d\n", mid);
            if (mid + 1 >= citations[mid]) {
                left = mid + 1;
            } else right = mid;
        }

        return left;
    }
};