class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       using ll = long long;
       ll count = 0, curr = 0;
       for (int left = 0, right = 0; right < nums.size(); right++)  {
            curr += nums[right];
            while (curr * (right - left + 1) >= k) curr -= nums[left++];
            count+= right - left + 1;
       }
       return count;

    }
};