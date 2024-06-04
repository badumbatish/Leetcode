/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;

        if (root->val == p->val || root->val == q->val) return root;
        auto a = lowestCommonAncestor(root->left, p, q);
        auto b = lowestCommonAncestor(root->right, p, q);

        if (a && b) return root;
        if (a) return a;
        if (b) return b;
        return nullptr;
    }
};