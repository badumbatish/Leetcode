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
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        while (head) {
            std::cout << "head: " << head->val << std::endl;
            if (prev == nullptr) {
                auto temp = head->next;
                prev = head;
                prev->next = nullptr;
                head = temp;
                continue;
            } else {
                std::cout << "Prev: " << prev->val << std::endl;
                auto temp = head->next;
                head->next = prev;
                prev = head;
                head = temp;
                continue;
            }
        }
        auto it = prev;
        while (it) {
            std::cout << it->val << std::endl;
            it = it->next;
        }
        if (prev) 
            std::cout << "Prev: " << prev->val << std::endl;

        return prev;
    }
};