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
    std::unordered_map<int, TreeNode*> parent_map;
    std::queue<TreeNode*> q;
    std::set<TreeNode*> visited;
    std::unordered_map<TreeNode*, std::pair<TreeNode*, string>> path_tracker;

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        auto start_node = find_node(root, startValue);
        populate_parent_map(root);


        q.push(start_node);
        visited.insert(start_node);

        while(!q.empty()) {
            TreeNode* current_node = q.front(); q.pop();
            if (current_node->val == destValue) {
                return back_track(current_node);
            }

            auto *left = current_node->left, *right = current_node->right;

            // Work up to the root
            if (parent_map.find(current_node->val) != parent_map.end()) {
                TreeNode* parent_node = parent_map[current_node->val];

                // If we haven't visited the parent,
                // We say that the path from the current node to parent node is UP 
                // Or from the parent node POV, current node goes up to reach it
                // And we visit the parent node next.
                if (visited.count(parent_node) == 0) {
                    q.push(parent_node);
                    path_tracker[parent_node] = {current_node, "U"};
                    visited.insert(parent_node);
                }
            }

            // Work down to the left
            // If we haven't visited the left
            // We say that the path from the current node to the left is LEFT
            if (left != nullptr && visited.count(left) == 0) {
                q.push(left);
                path_tracker[left] = {current_node, "L"};
                visited.insert(left);
            }

            // Work down to the right

            if (current_node->right != nullptr && visited.count(current_node->right) == 0) {
                q.push(current_node->right);
                path_tracker[current_node->right] = {current_node, "R"};
                visited.insert(current_node->right);
            }
        }
        
        return "";
    }

    TreeNode* find_node(TreeNode* root, int find) {
        if (root == nullptr) return nullptr;
        if (root->val == find) return root;
        if (auto l = find_node(root->left, find)) return l;
        if (auto r = find_node(root->right, find)) return r;

        return nullptr;
    }

    void populate_parent_map(TreeNode* root) {
        if (root == nullptr) return;
        if (root->left != nullptr) {
            parent_map[root->left->val] = root;
            populate_parent_map(root->left);
        }
        if (root->right != nullptr) {
            parent_map[root->right->val] = root;
            populate_parent_map(root->right);
        }
    }
    
    std::string back_track(TreeNode* root) {
        std::string path;

        while (path_tracker.count(root)) {
            path += path_tracker[root].second;
            root = path_tracker[root].first;
        }

        std::reverse(path.begin(), path.end());
        return path;
    }
};