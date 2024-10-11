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
    int rob(TreeNode* root) {
        auto rob_options = traverse(root);
        return std::max(rob_options.first, rob_options.second);
    }


    // {Rob current, rob next}
    std::pair<int, int> traverse(TreeNode* root) {
        if (!root) return {0, 0};
        
        auto left = traverse(root->left);
        auto right = traverse(root->right);

        int robbing_current = root->val + left.second + right.second;
        int robbing_next = std::max(left.first, left.second) + std::max(right.first, right.second);

        return {robbing_current, robbing_next};


    }
};