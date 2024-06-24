class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums.front();
        if (nums.size() == 2) return *std::ranges::max_element(nums);

        return max(rob_from_to(0, nums.size()-1, nums),
                    rob_from_to(1, nums.size(), nums));
    }

    int rob_from_to(int start, int end, std::vector<int>& houses)
    {
        int one_away = houses[start+1];
        int two_away = houses[start];

        int amount = max(one_away, two_away);
        for (int i = start+2; i < end; i++) 
        {
            amount = max(one_away, two_away + houses[i]);
            
            two_away = max(two_away, one_away);
            one_away = amount;
        }
        return amount;
    }
};