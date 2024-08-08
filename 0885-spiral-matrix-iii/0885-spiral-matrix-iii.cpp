class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        std::vector<std::vector<int>> dir {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        std::vector<std::vector<int>> traversed;


        for (int step = 1, direction = 0; traversed.size() < rows * cols;step++) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < step; j++) {
                    if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                        traversed.push_back({rStart, cStart});
                    }

                    rStart += dir[direction][0];
                    cStart += dir[direction][1];
                }

                direction = (direction + 1) % 4;
            }
           // step++;
        }
        return traversed;
    }
};