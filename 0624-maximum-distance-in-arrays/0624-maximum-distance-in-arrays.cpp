class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        std::vector<std::pair<int, int>> start, ending;
        int i = 0;
        for (auto &array : arrays) {
            start.push_back({array.front(), i});
            ending.push_back({array.back(), i});
            i++;
        }

        std::sort(start.begin(), start.end());
        std::sort(ending.begin(), ending.end());

        auto a = start.front();
        auto b = ending.back();

        if (a.second != b.second) return b.first - a.first;
        
        auto c = start[1];
        auto d = ending[ending.size() - 2];
        return std::max(d.first - a.first, b.first - c.first);
    }
};