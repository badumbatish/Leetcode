class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        std::ranges::sort(points, [](auto &a, auto &b) { return a[1] < b[1]; });

        int count = 1;
        int end = points.front()[1];

        for (int i = 1; i < points.size(); i++) {
            int start = points[i][0];
            // if the end point of the previous ballon and the start point of the previous balloon does not touch anymore, then we would have to shoot them seperately, thereby increasing the amount of arrows used by 1.
            if (start > end) {
                count++;
                end = points[i][1];
            }
        }

        return count;
    }
};