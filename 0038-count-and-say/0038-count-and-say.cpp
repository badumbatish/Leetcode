class Solution {
public:
    string countAndSay(int n) {
        std::string current_string = "1";

        for (int i = 2; i <= n; i++) {
            std::string next_string;

            for (int j = 0, k = 0; j < current_string.size(); j = k) {
                while (k < current_string.size() &&
                        current_string[k] == current_string[j]) {
                            k++;
                        }
                next_string += to_string(k - j) + current_string[j];
            }

            current_string = next_string;
        }

        return current_string;
    }
};