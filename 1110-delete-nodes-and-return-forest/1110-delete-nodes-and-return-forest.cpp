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
    std::vector<TreeNode*> result;
    std::set<int> to_delete_set;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto n : to_delete) to_delete_set.insert(n);
        if (root && to_delete_set.count(root->val) == 0) {
            result.push_back(root);
        }
        dfs(root);

        return result;
    }

    void dfs(TreeNode* node) {
        if (node == nullptr) return;
        
        if (to_delete_set.count(node->val)) {
            if (node->left && to_delete_set.count(node->left->val) == 0) result.push_back(node->left);
            if (node->right && to_delete_set.count(node->right->val) == 0) result.push_back(node->right);
            to_delete_set.erase(node->val);
            
        }
        if (node->left) {
            auto left_val = node->left->val;
            bool before = to_delete_set.count(left_val) == 1;
            dfs(node->left);
            bool after = to_delete_set.count(left_val) == 0;

            if (before  == true && after == true) {
                node->left = nullptr;
            }
        }

        if (node->right) {
            auto right_val = node->right->val;
            bool before = to_delete_set.count(right_val) == 1;
            dfs(node->right);
            bool after = to_delete_set.count(right_val) == 0;

            if (before  == true && after == true) {
                node->right = nullptr;
            }
        }
        return;
    }
};