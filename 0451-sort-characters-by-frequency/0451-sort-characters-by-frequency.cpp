class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char, int> freq;
        for (char ch : s) freq[ch]++;

        std::ranges::sort(s, [&](auto a, auto b) { 
            if (freq[a] == freq[b]) return a > b;
            return freq[a] > freq[b]; 
            });

        return s;
    }
};