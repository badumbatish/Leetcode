/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
    std::set<Node*> parents;
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        while (p) {
            parents.insert(p);
            p = p->parent;
        } 

        while (q) {
            if (parents.find(q) != parents.end()) return q;
            q = q->parent;
        }

        return nullptr;
    }
};