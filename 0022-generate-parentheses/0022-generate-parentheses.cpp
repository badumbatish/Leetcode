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
    void dfs() {
        if (temp.size() == n) {
            std::cout << temp << std::endl; 
            if (is_valid(temp))
                result.push_back(temp);
            return;
        }
        static std::array<std::string, 4> options = { "()", "((", "))", ")("};
        for (auto option : options) {
            temp += option;
            dfs();
            temp.pop_back();
            temp.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        this->n = n * 2;
        dfs();
        return result;
    }
};