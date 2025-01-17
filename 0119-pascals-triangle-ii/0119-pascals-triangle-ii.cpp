class Solution {
public:
    vector<int> getRow(int rowIndex) {
        std::vector<int> result(rowIndex + 1, 1);
        std::vector<int> temp(rowIndex + 1, 1);
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 1; j < i; j++) {
                temp[j] = result[j-1] + result[j];
            }
            std::swap(result, temp);
        }
        return result;
    }
};