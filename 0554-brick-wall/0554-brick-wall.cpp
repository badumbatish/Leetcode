class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        std::map<int, int> mp;

        for (auto& bricks : wall) {
            int sum = 0;
            for (int i = 0; i < bricks.size() - 1; i++) {
                sum += bricks[i];
                mp[sum]++;
            }
        }

        int mini = wall.size();
        for (auto &[key, value] : mp) {
            std::cout << key << " " << value << std::endl;
            mini = std::min(mini, int32_t(wall.size()) - value);
        }
       
        return mini;
    }
};