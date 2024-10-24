class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> num_strings;

        for (auto num : nums) num_strings.push_back(to_string(num));

        std::sort(num_strings.begin(), num_strings.end(), [](auto &a, auto &b) { return a + b > b + a;});

        if (num_strings.front() == "0") return "0";

        std::string largest_num;

        for (auto &num_str : num_strings) largest_num += num_str;

        return largest_num;
    }
};