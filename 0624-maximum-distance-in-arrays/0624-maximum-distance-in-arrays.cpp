class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = arrays.front().front();
        int maxi = arrays.front().back();

        int dist = 0;
        for (int i = 1; i < arrays.size(); i++) {
            auto &array = arrays[i];
            dist = std::max(dist, array.back() - mini);
            dist = std::max(dist, maxi - array.front());

            mini = std::min(mini, array.front());
            maxi = std::max(maxi, array.back());
        }

        return dist;
    }
};