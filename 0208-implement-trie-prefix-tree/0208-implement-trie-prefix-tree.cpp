class Node {
public:
    std::array<std::shared_ptr<Node>, 26> children;
    bool flag;

    Node() {
        this->flag = false;
    }
};

class Trie {
public:
    std::shared_ptr<Node> root;
    Trie() {
        root = std::make_shared<Node>();
    }
    
    
    
    std::shared_ptr<Node> get_stem(std::string word, bool auto_create = false) {
        auto current = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(!current->children[word[i]-'a'] && auto_create == false) return nullptr;
            if(!current->children[word[i]-'a'] && auto_create == true) 
                current->children[word[i]-'a'] = std::make_shared<Node>();
            current = current->children[word[i]-'a'];
        }
        return current;
    }

    void insert(string word) {
       auto stem = get_stem(word, true);
       stem->flag = true;
    }

    bool search(string word) {
        auto stem = get_stem(word);

        return stem != nullptr && stem->flag == true;
    }
    
    bool startsWith(string prefix) {
        auto stem = get_stem(prefix);
        return stem != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */