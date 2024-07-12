class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::stack<int> stck;
        std::map<int, int> map_num_to_greater;

        for (auto num : nums2) {
            while (!stck.empty() && num > stck.top()) {
                map_num_to_greater[stck.top()] = num;
                stck.pop();
            }

            stck.push(num);
        }

        while (!stck.empty()) {
            map_num_to_greater[stck.top()] = -1;
            stck.pop();
        }
        for (auto &num : nums1){ 
            num = map_num_to_greater[num];
        }

        return nums1;
    }
};