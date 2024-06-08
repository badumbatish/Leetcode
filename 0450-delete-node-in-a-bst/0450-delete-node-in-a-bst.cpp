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
    TreeNode* prev_left = nullptr;
    TreeNode* prev_right = nullptr;

    int key = 0;
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // When traversing the search S, keep a prev P 

        // Found the search S, go to the right of search and find left most child L

        // If P->left == S, set P->left = L
        // Else if P->right == S, set P->right = R

        // Set R->right = S->right.

        // Done

        if (root == nullptr) return nullptr;

        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root-> val) root->right = deleteNode(root->right, key);
        else {
            if (root->right == nullptr) return root->left;
            if (root->left == nullptr) return root->right;
            auto tmp = smallest(root->right);
            root->val = tmp->val;
            root->right = deleteNode(root->right, tmp->val);
        }
        
        return root;
    }
    TreeNode* smallest(TreeNode* root) {
        if (root == nullptr || root->left == nullptr) return root;

        return smallest(root->left);
    }
};