class Solution {
public:
    std::unordered_map<int, int> memo;

    int recursive_with_memo(int index, std::string& str) {
        if (memo.contains(index)) {
            return memo[index];
        }

        if (index == str.length()) return 1;
        if (str[index] == '0') return 0;
        if (index == str.length() - 1) return 1;

        auto ans = recursive_with_memo(index+1, str);
        if (stoi(str.substr(index, 2)) <= 26) 
            ans += recursive_with_memo(index + 2, str);

        memo[index] = ans;

        return ans;
    }
    int numDecodings(string s) {
        return recursive_with_memo(0, s);
    }
};