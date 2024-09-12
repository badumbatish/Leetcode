class Solution {
    int longest_path = 1;
    std::vector<std::vector<int>> children;
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();

        // a graph that contains i and children of i 
        children = std::vector<std::vector<int>>(n);
        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        dfs(0, s);

        return longest_path;
    }

    int dfs(int current, std::string&s) {
        int longest_chain = 0, second_longest_chain = 0;

        for (int child : children[current]) {
            int longest_chain_start_from_child = dfs(child, s);
            
            // if parent and children has the same character, let's not consider the longest chain
            // althought we're still computing the longest path starting from the child 
            if (s[current] == s[child]) continue;
            
            // Case 1: where we have have a new longest chain
            if (longest_chain_start_from_child > longest_chain) {
                second_longest_chain = longest_chain;
                longest_chain = longest_chain_start_from_child;
            } else if (longest_chain_start_from_child > second_longest_chain) {
                // Case 2: where we have a new second longest chain
                second_longest_chain = longest_chain_start_from_child;
            }
        } 

        longest_path = max(longest_path, longest_chain + second_longest_chain + 1);
        return longest_chain + 1;
    }
};