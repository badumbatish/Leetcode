class Solution {
private:
    std::unordered_map<int, int> u_map = {};

public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        return dp(cost.size() - 1, cost);
    }

    int dp(int index, std::vector<int> &cost) {
        // total cost of current = min(index - 2, index - 1) + current_cost
        if (index == 0) {
            u_map[0] = cost[0];
            return cost[0];
        }
        if (index == 1) {
            u_map[1] = cost[1];
            return cost[1];
        }

        if (u_map.find(index-1) == u_map.end()) {
            u_map[index-1] = dp(index - 1, cost);
        }
        if (u_map.find(index-2) == u_map.end()) {
            u_map[index-2] = dp(index - 2, cost);
        }
        if (u_map.find(index) == u_map.end()) {
            u_map[index] = min(u_map[index-1], u_map[index-2]) + cost[index];
        }
        return u_map[index];
    }
};