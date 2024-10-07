class Solution {
public:
bool validWordAbbreviation(string word, string abbr) {
    int w = 0, a = 0;
    
    while (w < word.size() && a < abbr.size()) {
        if (isdigit(abbr[a])) {
            // Handle invalid leading zero case
            if (abbr[a] == '0') return false;
            
            // Extract the full number from abbr
            int num = 0;
            while (a < abbr.size() && isdigit(abbr[a])) {
                num = num * 10 + (abbr[a] - '0');
                a++;
            }
            // Skip num characters in word
            w += num;
        } else {
            // Check if characters match
            if (word[w] != abbr[a]) return false;
            w++;
            a++;
        }
    }
    
    // Both word and abbr should be fully traversed
    return w == word.size() && a == abbr.size();
}
};