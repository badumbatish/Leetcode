class Solution {
public:
    // A helper function to calculate the size of the subtree
    int countNodes(TreeNode* node) {
        if (!node) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // Step 1: Find the node with value x and its subtree sizes
        TreeNode* xNode = findNode(root, x);
        int leftSize = countNodes(xNode->left);
        int rightSize = countNodes(xNode->right);
        
        // Step 2: Calculate the size of the remaining nodes
        int parentSize = n - (leftSize + rightSize + 1); // total - left - right - x

        // Step 3: Check if the second player can guarantee a win
        // They can win if any of these sizes is greater than half of n
        return leftSize > n / 2 || rightSize > n / 2 || parentSize > n / 2;
    }

private:
    // A helper function to find the node with value x
    TreeNode* findNode(TreeNode* node, int x) {
        if (!node) return nullptr;
        if (node->val == x) return node;
        TreeNode* left = findNode(node->left, x);
        return left ? left : findNode(node->right, x);
    }
};
