class Solution {
public:
    int countInVec(std::vector<int>&row) {
        int left = -1, right = row.size() - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (row[mid] < 0) right = mid;
            else left = mid;
        }
        return row[right] < 0 ? row.size() - right : 0;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int sum = 0;
        for (auto & row : grid) {
            auto res = countInVec(row);
            std::cout << res << std::endl;
            sum += res;
        }
        return sum;
    }
};