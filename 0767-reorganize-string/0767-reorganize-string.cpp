class Solution {
public:
    string reorganizeString(string s) {
        std::map<int, std::vector<char>> freq_to_chars_map;
        std::map<char, int> freq_map;
        for (auto ch : s) freq_map[ch]++;

        for (auto [ch, freq] : freq_map) freq_to_chars_map[freq].push_back(ch);

        int max_freq = s.size() - 1; 
        std::string result_str = "";
        
        for (int i = max_freq; i >= 1; i--) {
            auto& chs = freq_to_chars_map[i];
            for (auto ch : chs) {
                if (result_str.empty() || result_str.back() != ch) {
                    result_str += ch;
                    freq_to_chars_map[i-1].push_back(ch);
                }
                else return "";
            }
        }

        return result_str;
    }
};