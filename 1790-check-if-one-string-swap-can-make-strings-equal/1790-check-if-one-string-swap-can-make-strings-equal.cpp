class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        std::vector<int> candidate;
        for (int i = 0; i < s1.size(); i++)  
            if (s1[i] != s2[i]) candidate.push_back(i);

        if (candidate.size() == 1 || candidate.size() > 2) return false;
        if (candidate.size() == 0) return true;
        if (candidate.size() == 2) {
            return s1[candidate[0]] == s2[candidate[1]] && s1[candidate[1]] == s2[candidate[0]];
        }
        return false;
    }
};