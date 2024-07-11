class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for(auto i : nums) freq[i]++;

        return std::ranges::max_element(freq)->first;
    }
};