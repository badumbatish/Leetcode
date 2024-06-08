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
    int maxLevelSum(TreeNode* root) {
        std::queue<std::pair<TreeNode*, int>> q;

        if (root == nullptr) return 0;

        q.push({root, 1});

        int max_level = 1;
        int max_sum = root->val;
        int cur_sum = root->val;
        int prev_level = 0;
        do  {
            auto [node, level] = q.front(); q.pop();

            if (prev_level != level) {
                if (cur_sum > max_sum) {
                    max_level = prev_level;
                    max_sum = cur_sum;
                }
                prev_level = level;
                cur_sum = 0;
            }

            if (node) cur_sum += node->val;
            if (node) q.push({node->left, level + 1});
            if (node) q.push({node->right, level + 1});
        } while (!q.empty());

        return max_level;
    }
};