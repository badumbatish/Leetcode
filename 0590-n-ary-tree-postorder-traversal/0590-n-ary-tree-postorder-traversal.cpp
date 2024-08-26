/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    std::vector<int> result;
public:
    vector<int> postorder(Node* root) {
        dfs(root);
        return result;
    }

    void dfs(Node* root) {
        if (!root) return;
        
        for (auto neighbor : root->children) 
            dfs(neighbor);

        result.push_back(root->val);
    }
};