class Solution {
public:

    auto make_map(std::string_view sv) {
        std::map<char, int> mp;
        for (auto i : sv) {
            mp[i]++;
        }

        return mp;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::map<char, int>, std::vector<std::string>> mp;

        for (auto s : strs) {
            auto temp_mp = make_map(s);
            mp[std::move(temp_mp)].push_back(std::move(s));
        }

        std::vector<std::vector<std::string>> res;
        for(auto i : mp) res.emplace_back(std::move(i.second));

        return res;
    }
};