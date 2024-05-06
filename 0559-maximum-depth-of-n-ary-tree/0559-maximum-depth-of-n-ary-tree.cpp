
// Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };


class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        std::vector<int> vec = {0};

        for (int i = 0; i < root->children.size(); i++) {
            vec.push_back(maxDepth(root->children[i]));
        }

        return 1 + *std::max_element(vec.begin(), vec.end());
    }
};