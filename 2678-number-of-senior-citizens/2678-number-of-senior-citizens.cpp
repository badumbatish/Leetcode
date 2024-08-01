class Solution {
public:
    int countSeniors(vector<string>& details) {
        return std::ranges::count_if(details, [&](const auto& detail){ return detail.substr(11, 2) > "60";});
        
    }
};