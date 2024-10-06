class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if (s2.size() < s1.size()) return false;
        auto len = s1.size();

        std::map<char, int> s1_sig;
        for (int i = 0; i < len; i++) {
            s1_sig[s1[i]]++;
        }

        std::map<char, int> sub_sig;
        for (int i = 0; i < s2.size() - len + 1; i++) {
             
            for (int j = 0; j < len; j++) {
                sub_sig[s2[i+j]]++;
            }
            if (sub_sig == s1_sig) return true;
            sub_sig = std::map<char, int>();
        }

        std::cout << "hi" << std::endl;
        return false;
    }
};