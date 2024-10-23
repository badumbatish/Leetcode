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
    std::vector<int> level_sum = std::vector<int>(100000, 0);
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        dfs1(root, 0);
        dfs2(root, 0);
        if (root) root->val = 0;
        return root;
    }


    void dfs1(TreeNode* root, int level) {
        if (!root) return;

        if (auto left = root->left) {
            level_sum[level] += left->val;
            dfs1(left, level + 1);
        }
        if (auto right = root->right) {
            level_sum[level] += right->val;
            dfs1(right, level + 1);
        }
    } 
    void dfs2(TreeNode* root, int level) {
        if (!root) return;
        int sum = 0;
        auto left = root->left;
        auto right = root->right;
        if (left) sum += left->val;
        if (right) sum += right->val;
        if (left) {
            left->val = level_sum[level] - sum;
            dfs2(left, level + 1);
        }
        if (right) {
            right->val = level_sum[level] - sum;
            dfs2(right, level + 1);
        }

    } 
};