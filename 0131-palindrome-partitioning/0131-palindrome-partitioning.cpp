class Solution {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> temp;
    std::map<std::pair<int, int>, bool> mp;
    
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);

        return result;
    }

    void dfs(std::string& s, int start) {
        if (start >= s.length()) result.push_back(temp);
        for (int end = start; end < s.length(); end++) {
            if (s[start] == s[end] && (end - start <= 2 || mp[{start+1,end - 1}] == true)) {
                mp[{start, end}] = true;
                temp.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1);
                temp.pop_back();
            }
        }
    }
};