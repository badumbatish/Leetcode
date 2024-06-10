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
    std::vector<int> leaf_seq_1, leaf_seq_2;
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        traverse(root1, leaf_seq_1);
        traverse(root2, leaf_seq_2);

        if (leaf_seq_1.size() != leaf_seq_2.size()) return false;

        for (int i = 0; i < leaf_seq_1.size(); i++) 
        {
            if (leaf_seq_1[i] != leaf_seq_2[i]) return false;
        }

        return true;
    }

    void traverse(TreeNode* root, std::vector<int>& vec) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) 
        {
            vec.push_back(root->val);
            return;
        }

        traverse(root->left, vec);
        traverse(root->right, vec);
    }
};