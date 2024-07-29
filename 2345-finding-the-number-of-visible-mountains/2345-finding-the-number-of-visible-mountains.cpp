class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        int repeated = 0;
        std::vector<std::vector<int>> intervals;

        for (auto peak : peaks) {
            intervals.push_back({peak[0] - peak[1], peak[0] + peak[1]});
        }
        std::ranges::sort(intervals);

        std::stack<std::vector<int>> st;

        bool repeated_before = false;

        for (int i = 0; i < intervals.size(); i++) {
            if (!repeated_before && !st.empty() && st.top() == intervals[i]) {
                repeated++;
                repeated_before = true;
            }
            if (i > 0 && intervals[i][0] != intervals[i-1][0] && intervals[i][1] != intervals[i][1]) {
                repeated_before = false;
            }

            while (!st.empty() && (st.top()[0] >= intervals[i][0] && st.top()[1] <= intervals[i][1])) {
                st.pop();
            } 

            if (!st.empty() && (st.top()[0] <= intervals[i][0] && st.top()[1] >= intervals[i][1])) continue;

            st.push(intervals[i]);
        }

        return max((int)st.size() - repeated, 0);
    }
};