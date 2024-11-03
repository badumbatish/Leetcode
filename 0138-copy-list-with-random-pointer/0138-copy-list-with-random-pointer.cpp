/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    std::unordered_map<Node*, Node*> visited_nodes;
public:
    Node* copyRandomList(Node* head) {
       if (!head) return nullptr;

       if (this->visited_nodes.find(head) != visited_nodes.end()) return visited_nodes[head];

        Node* node = new Node(head->val, nullptr, nullptr);

        this->visited_nodes[head] = node;

        node->next = this->copyRandomList(head->next);
        node->random = this->copyRandomList(head->random);

        return node;

    }
};