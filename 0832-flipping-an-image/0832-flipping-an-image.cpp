class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for (auto &row : image) {
            std::ranges::reverse(row);
        }
        for (auto &row : image) {
            for (auto &col : row) {
                col = std::abs(col - 1);
            }
        }

        return image;
    }

    
};