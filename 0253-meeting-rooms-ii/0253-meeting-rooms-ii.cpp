class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::vector<int> starts, ends;

        for (auto &e : intervals) {
            starts.push_back(e[0]);
            ends.push_back(e[1]);
        }
        std::ranges::sort(starts);
        std::ranges::sort(ends);
        int i = 0, j = 0;
        int curr_int = 0, max_int = 0;

        while (i < intervals.size()) {
            if (starts[i] < ends[j]) {
                i++;
                curr_int++;
            } else {
                j++;
                curr_int--;
            }

            max_int = max(max_int, curr_int);
        }

        return max_int;
    }
};