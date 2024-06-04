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
    std::map<int, int> mp;
    int level = 0;
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> vec;
        dfs(root);
        for (auto [k, v] : mp) vec.push_back(v);

        return vec;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        
        if (mp.find(level) == mp.end()) mp[level] = root->val;

        level++; dfs(root->right);
        dfs(root->left); level--;

    }
};