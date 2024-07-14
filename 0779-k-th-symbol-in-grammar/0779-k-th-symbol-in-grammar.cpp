class Solution {
public:
    int kthGrammar(int n, int k) {
        return dfs(n,k,0);
    }

    int dfs(int n, int k, int root_val) {
        if (n == 1) return root_val;

        int total_nodes = pow(2, n - 1);

        if (k > (total_nodes / 2)) {
            int next_root_val = (root_val == 0) ? 1 : 0;
            return dfs(n - 1, k - (total_nodes / 2), next_root_val);
        } else {
            int next_root_val = (root_val == 0) ? 0 : 1;
            return dfs(n-1, k, next_root_val);
        }
    }
};