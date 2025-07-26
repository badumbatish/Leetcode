struct Trie {
    // current node structure's serialized representation
    string serial;
    // current node's child nodes
    unordered_map<string, std::unique_ptr<Trie>> children;
};

std::unique_ptr<Trie>
construct_trie(std::vector<std::vector<std::string>>& paths) {
    std::unique_ptr<Trie> root = std::make_unique<Trie>();

    for (const auto& path : paths) {
        Trie* cur = root.get();
        for (const string& node : path) {
            if (!cur->children[node]) {
                cur->children[node] = std::make_unique<Trie>();
            }
            cur = cur->children[node].get();
        }
    }
    return root;
}

void construct_frequency_map(std::unordered_map<string, int>& mp, Trie* root) {
    // post-order traversal based on depth-first search, calculate the
    // serialized representation of each node structure
    if (!root || root->children.empty())
        return;

    std::vector<std::string> v;

    for (const auto& [folder, child] : root->children) {
        construct_frequency_map(mp, child.get());
        v.push_back(folder + "(" + child->serial + ")");
    }
    // to prevent issues with order, sorting is needed
    sort(v.begin(), v.end());
    for (string& s : v) {
        root->serial += std::move(s);
    }
    mp[root->serial] += 1;    
}
class Solution {
public:
    std::vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>>& paths) {
        // root node
        auto root_node = construct_trie(paths);
        // hash table records the occurrence times of each serialized
        // representation

        std::unordered_map<string, int> freq;
        construct_frequency_map(freq, root_node.get());

        // record the path from the root node to the current node.
        vector<vector<string>> ans;

        vector<string> path;
        function<void(Trie*)> operate = [&](Trie* node) {
            // if the serialization appears more than once in the hash table, it
            // needs to be deleted.
            if (freq[node->serial] > 1) {
                return;
            }
            // otherwise add the path to the answer
            if (!path.empty()) {
                ans.push_back(path);
            }
            for (const auto& [folder, child] : node->children) {
                path.push_back(folder);
                operate(child.get());
                path.pop_back();
            }
        };

        operate(root_node.get());
        return ans;
    }
};