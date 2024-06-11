/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = head;

        auto cur = head;
        while (cur != nullptr) {
            // compare to the previous and check if they're equal
            // if they are equal, we should bypass
            if (equal(prev, cur)) {
                prev->next = cur->next;
            } else {
                // if not, we can just update the previous
                prev = cur;
            }

            // proceed with the current chain.
            cur = cur->next;
        }

        return head;
    }

    bool equal(ListNode* a, ListNode* b) {
        if (a == nullptr && b == nullptr) return true;
        if (a == nullptr || b == nullptr) return false;

        return (a->val == b->val);
    }
};