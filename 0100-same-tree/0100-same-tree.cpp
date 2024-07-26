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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==q && p == nullptr) return true;
        auto same_left = [&]() {
             return isSameTree(p->left, q->left);
             };
        auto same_right = [&]() {
             return isSameTree(p->right, q->right);
             };
        auto same_node = [&]() { 
            return p != nullptr && q != nullptr && p->val == q->val; 
            };
        
        return same_node() && same_left() && same_right();
    }
};