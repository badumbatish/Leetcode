class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (auto &details : details) {
            if (std::stoi(details.substr(11, 2)) > 60) count++;
        }

        return count;
    }
};