/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<std::pair<int, int>> val_levels = {};
        std::queue<std::pair<TreeNode*, int>> q = {};

        if (root != nullptr) q.push({root, 0});
        val_levels = level_traverse(q);

        std::vector<int> res = filt_level(val_levels);
        std::reverse(res.begin(), res.end());
        return res;
    }

    std::vector<std::pair<int, int>> level_traverse(std::queue<std::pair<TreeNode*, int>> q) {
        std::vector<std::pair<int, int>> res = {};
        
        while (!q.empty()) {
            auto temp = q.front();
            auto curr_level = temp.second;
            q.pop();

            if (temp.first == nullptr) continue;
            res.push_back({temp.first->val, temp.second});

            q.push({temp.first->left, curr_level + 1 });
            q.push({temp.first->right, curr_level + 1});
        }

        return res;
    }

    std::vector<int> filt_level(std::vector<std::pair<int, int>> levels) {
        std::vector<int> res = {};
        if (levels.size() == 0) return {};
       
        auto temp_back = levels.back();
        levels.push_back({temp_back.first, temp_back.second + 1});
        for (int i = levels.size() - 1; i >= 1; i--) {
            auto curr = levels[i];
            auto next = levels[i-1];

            if (curr.second != next.second) {
                res.push_back(next.first);
            }
        }
        //res.push_back(levels.front().first);
        return res;
    }
};