class Solution {
public:
    int maxVowels(string s, int k) {
        int left = 0;
        int right = 0; 

        int count = 0;

        for (int i = 0; i < k; i++) { // Get a window of length k
            count += is_vowels(s[i]);
        }

        int max_count = count; // the max count is the count of the first window

        for (int i = k; i < s.size(); i++) { 
            count += (is_vowels(s[i]) - is_vowels(s[i-k])); // Get the count of the current window
            max_count = max(count, max_count); // Update the window
        }

    
        return max_count;
    }

    bool is_vowels(char ch) {
        return ch == 'a' || ch == 'e' || ch =='i' || ch == 'o' || ch == 'u';
    }
};