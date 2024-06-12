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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return tree_construction(nums, 0, nums.size() - 1);
    }

    TreeNode* tree_construction(std::vector<int>& nums, int start, int end)
    {
        if (start > end) return nullptr;

        auto mid = (start+end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = tree_construction(nums, start, mid - 1);
        root->right = tree_construction(nums, mid + 1, end);

        return root;
    }
};