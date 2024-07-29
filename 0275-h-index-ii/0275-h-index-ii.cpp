class Solution {
public:
    int hIndex(vector<int>& citations) {

        int64_t left = 0, right = citations.size();

        while (left < right) {
            int64_t mid = left + (right - left) / 2;
            if (citations[mid] >= citations.size() - mid) right = mid;
            else left = mid + 1;
        }

        return citations.size() - left;
    }
};