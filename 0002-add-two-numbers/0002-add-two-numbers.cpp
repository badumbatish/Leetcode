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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);

        int carry = 0;
        ListNode* prev = head; 
        while (l1 || l2) {
            auto a = l1 ? l1->val : 0;
            auto b = l2 ? l2->val : 0;
            auto sum = (a + b + carry);
            auto* h = new ListNode(sum % 10);
            carry = sum / 10; 
            prev->next = h;
            prev = h;            

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (carry != 0) {
            auto* h = new ListNode(1);
            prev->next = h;
            prev = h;
        }

        
        return head->next;

    }
};