class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int total_score = 0;
        std::string high_pair = x > y ? "ab" : "ba";
        std::string low_pair = x <= y ? "ab" : "ba";


        std::string string_first_pass = remove_substring(s, high_pair);
        int remove_pair_count = (s.size() - string_first_pass.size()) / 2;

        total_score += remove_pair_count * max(x, y);

        std::string string_second_pass = remove_substring(string_first_pass, low_pair);

        remove_pair_count = (string_first_pass.size() - string_second_pass.size()) / 2;

        total_score += remove_pair_count * min(x, y);

        return total_score;
    }

    private:
    std::string remove_substring(const std::string& input, const std::string& target_pair) {
        std::stack<char> char_stack;

        for (char current_char : input) {

            if (current_char == target_pair[1] && !char_stack.empty() && char_stack.top() == target_pair[0]) {
                char_stack.pop();
            } else {
                char_stack.push(current_char);
            }
        }

        std::string remaining_chars;
        while (!char_stack.empty()) {
            remaining_chars += char_stack.top();
            char_stack.pop();
        }

        std::reverse(remaining_chars.begin(), remaining_chars.end());

        return remaining_chars;
    }
};