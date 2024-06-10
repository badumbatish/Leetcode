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
    int goodNodes(TreeNode* root) {
        return get_good_nodes(root, INT32_MIN);
    }

    int get_good_nodes(TreeNode* node, int currMax) {
        if(node == nullptr) return 0;

        auto new_max = max(currMax, node->val);
        auto left = get_good_nodes(node->left, new_max);
        auto right = get_good_nodes(node->right, new_max);
        
        if (node->val >= currMax)
            return 1 +  left + right;

        return 0 + left + right;
    }
};