class Solution {
    int rows;
    std::map<std::pair<int, int>, int> ump;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        rows = triangle.size();
        ump[{0, 0}] = triangle[0][0];

        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) ump[{i, j}] = triangle[i][j] + ump[{i-1, j}];
                else if (j == triangle[i].size()-1) ump[{i, j}] = triangle[i][j] + ump[{i-1, j-1}];
                else ump[{i, j}] = triangle[i][j] + min(ump[{i-1, j}], ump[{i-1, j-1}]);

                std::cout << ump[{i,j}] << std::endl;
            }
        }

        int mimi = INT_MAX;
        for (int j = 0; j < triangle[triangle.size()-1].size(); j++) {
            mimi = std::min(ump[{triangle.size()-1, j}], mimi);
        }

        return mimi;
    }
};