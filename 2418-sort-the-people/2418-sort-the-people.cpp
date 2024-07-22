class Solution {
public:
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    std::vector<std::pair<int, std::string>> people(names.size());
    std::ranges::transform(heights, names, people.begin(),
                    [](int h, std::string&n) { return std::pair(h, n); });
    std::ranges::sort(people, std::greater());
    std::ranges::transform(people, names.begin(),
                    [](const auto& p) { return p.second; });
    return names;
}
};