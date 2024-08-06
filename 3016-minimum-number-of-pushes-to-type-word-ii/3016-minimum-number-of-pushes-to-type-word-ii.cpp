class Solution {
public:
    int minimumPushes(string word) {
        std::unordered_map<char, int> freq_char;
        for (auto ch : word) freq_char[ch]++;

        std::vector<std::pair<int, char>> sorted_freq;
        for (auto [ch, freq] : freq_char) sorted_freq.push_back({freq, ch});
        std::sort(sorted_freq.rbegin(), sorted_freq.rend());

        std::unordered_map<char, int> assigned_char_weight;
        int cycle = 8;
        int weight = 1;
        for (auto [freq, ch] : sorted_freq) {
            assigned_char_weight[ch] = weight;
            cycle--;
            if (cycle == 0) {
                weight++;
                cycle = 8;
            }
        }

        int sum = 0;
        for (auto [ch, freq] : freq_char) sum += assigned_char_weight[ch] * freq;
        
       
        return sum;
    }
};