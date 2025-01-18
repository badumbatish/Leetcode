#include <ranges>

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        std::unordered_map<int, std::unordered_set<int>> mp;
        for (auto  point : points) {
            mp[point[0]].insert(point[1]);
        }

        int min_area = std::numeric_limits<int>::max();
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];


                if (x1 != x2 && y1 != y2) {
                    if (mp[x1].contains(y2) && mp[x2].contains(y1)) {
                        min_area = std::min(min_area, abs(x1-x2) * abs(y1 - y2));
                    }
                }
            }
        } 
        return min_area != std::numeric_limits<int>::max() ? min_area : 0;
    }
};