class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        std::unordered_set<int> prefixes;

        for (int val : arr1) {
            while (!prefixes.count(val) && val > 0) {
                prefixes.insert(val);
                val /= 10;
            }
        }


        int longest_len = 0;

        for (int val : arr2) {
            while (!prefixes.count(val) && val > 0) {
                val /= 10;
            }

            if (val > 0) 
                longest_len = max(longest_len, static_cast<int>(log10(val) + 1));
        }

        return longest_len;
    }
};