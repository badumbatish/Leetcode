class Solution {
public:
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int, string>> people(names.size());
    ranges::transform(heights, names, people.begin(), 
                      [](int h, string& n) { return std::pair{h, n}; });
    ranges::sort(people, greater{}, &pair<int, string>::first);
    ranges::transform(people, names.begin(), 
                      [](const auto& p) { return p.second; });
    return names;
}
};