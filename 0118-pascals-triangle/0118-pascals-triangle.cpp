class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> result;
        result.push_back({1});
        for (int i = 2; i <= numRows; i++) {
            std::vector<int> temp;
            for (int j = 0; j < i; j++) {
                if (j == 0)  temp.push_back(1);
                else if (j == i - 1) temp.push_back(1);
                else temp.push_back(result.back()[j-1] + result.back()[j]);
            }
            result.push_back(temp);
        } 
        return result;
    }
};