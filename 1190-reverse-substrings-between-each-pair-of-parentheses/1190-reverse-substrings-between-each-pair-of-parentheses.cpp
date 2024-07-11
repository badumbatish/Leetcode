class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();

        std::stack<int> open_par_indices;
        std::vector<int> pair_index(n);

        for(int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open_par_indices.push(i);
            }
            if (s[i] == ')') {
                int j = open_par_indices.top();
                open_par_indices.pop();
                pair_index[i] = j;
                pair_index[j] = i;
            }
        }

        std::string result;

        for (int curr_index = 0, direction = 1; curr_index < n; curr_index += direction) {
            if (s[curr_index] == '(' || s[curr_index] == ')') {
                curr_index = pair_index[curr_index];
                direction = -direction;
            } else {
                result += s[curr_index];
            }
        }

        return result;
    }
};