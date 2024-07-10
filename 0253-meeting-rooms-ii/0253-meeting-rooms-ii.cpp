class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::vector<int> start_points {};
        std::vector<int> end_points {};

        for (auto vec : intervals) {
            start_points.push_back(vec[0]);
            end_points.push_back(vec[1]);
        }

        std::ranges::sort(start_points);
        std::ranges::sort(end_points);

        int i = 0, j = 0;
        int current_intersections = 0;
        int max_intersection = 0;
        while (i < start_points.size()) {
            if (start_points[i] < end_points[j]) {
                current_intersections++;
                i++;
            } else {
                current_intersections--;
                j++;
            }

            max_intersection = std::max(max_intersection, current_intersections);
        }

        return max_intersection;
    }
};