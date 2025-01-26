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
    int level = 1; 
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::deque<TreeNode*> q;
        if (root) {
            if (root->left) q.push_back(root->left);
            if (root->right) q.push_back(root->right);
        }

        while (!q.empty()) {
            int n = q.size();
            if (level % 2 == 1) {
                for (int i = 0; i < q.size() / 2; i++) {
                    std::swap(q[i]->val, q[q.size() - 1- i]->val);
                }
            }
            while (n--) {
                auto node = q.front();
                q.pop_front();
                if (node->left) q.push_back(node->left);
                if (node->right) q.push_back(node->right);
            }
            level++;
        }
        return root;
    }
};