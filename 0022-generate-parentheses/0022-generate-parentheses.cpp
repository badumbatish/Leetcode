class Solution {
    bool is_valid(const std::string& paren) {
        int left_count = 0;
        for(auto ch : paren) {
            if (ch == '(') left_count++;
            else if (ch == ')') {
                if (left_count == 0) return false;
                left_count--;
            }
        }
        return left_count == 0;
    }
    std::string temp = "";
    int n;
    std::vector<std::string> result;
    void dfs(int left_count = 0, int right_count = 0) {
        if (temp.size() == n * 2) {
            result.push_back(temp);
            return;
        }
        if (left_count < n) {
            temp += '(';
            dfs(left_count+1, right_count);
            temp.pop_back();
        }
        if (left_count > right_count) {
            temp += ')';
            dfs(left_count, right_count+1);
            temp.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n ;
        dfs();
        return result;
    }
};