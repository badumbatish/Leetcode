class Solution {
public:
    string compressedString(string word) {
       
       std::string result = "";

       recursive(result, word, 0);

       return result;
    }

    void recursive(std::string& result, const std::string &word, int index) {
        if (index >= word.size()) return;
        char ch = word[index];

        // go from 1 to 9.
        int count = 1;
        for (int i = 1; i < 9; i++) {
            if (word[index+ i] == ch) count++;
            else break;
        }

        result += std::to_string(count) + ch;
        recursive(result, word, index+count); 
    }
};