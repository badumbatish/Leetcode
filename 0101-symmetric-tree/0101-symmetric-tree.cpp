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
    bool isSymmetric(TreeNode* root) {
        return traverse(root, root);
    }

    bool traverse(TreeNode* a, TreeNode* b)
    {
        if (!a && !b) return true;
        if (!a || !b) return false;

        return (a->val == b->val) && traverse(a->left, b->right) && traverse(a->right, b->left);
    }
};