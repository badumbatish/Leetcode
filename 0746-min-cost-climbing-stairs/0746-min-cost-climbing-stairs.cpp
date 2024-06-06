class Solution {
public:
    int minCostClimbingStairs(std::vector<int> &cost) {
        cost.push_back(0);
        int down1 = 0;
        int down2 = 0;
        int current = cost[2];

        for (auto i = 2; i < cost.size(); i++) {
            // From climb 1 step pov, you're paying cost[i-1] and the already minimum paid cost to climb the previous i-1 steps.

            // From climb 2 step pov, you're paying cost[i-2] and the already minimum paid cost to climb the previous i-2 steps.
            current = std::min(cost[i-1] + down1, cost[i-2] + down2);
            down2 = down1;
            down1 = current;
        }

        return current;

    }
};