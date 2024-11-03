class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s2.size() < s1.size()) return false;
        auto len = s1.size();

        std::map<char, int> s1_sig;
        std::map<char, int> sub_sig;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            s1_sig[ch];
            sub_sig[ch];
        }
        for (int i = 0; i < len; i++) {
            s1_sig[s1[i]]++;
            sub_sig[s2[i]]++;
        }

        for (int i = 0; i < s2.size() - len ; i++) {
            if (sub_sig == s1_sig) return true;
            sub_sig[s2[i]]--;
            sub_sig[s2[i+len]]++;
        }

        return sub_sig == s1_sig;
    }
};