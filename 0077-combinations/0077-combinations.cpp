class Solution {
    using Combination = std::vector<int>;

    int n, k;
    std::vector<Combination> result;
    void backtrack(int index, Combination& combination) {
        if (combination.size() == k) {
            result.push_back(combination);
            return;
        }
         // Prune: If not enough numbers left to complete the combination, stop early
        if (index > n || (n - index + 1) < (k - combination.size())) {
            return;
        } 

        // We start from index instead of 0 to avoid duplication
        for (int i = index; i < n; i++) {
            combination.push_back(i+1);
            backtrack(i+1, combination);
            combination.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;

        Combination combination;
        backtrack(0, combination);

        return this->result;
    }
};