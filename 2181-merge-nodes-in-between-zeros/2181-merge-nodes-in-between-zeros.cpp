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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* anchor = head->next;
        ListNode* prev = head;

        int sum = 0;

        while(curr) {
            if (curr->val == 0) {
                anchor->next = curr->next;
                anchor->val = sum;
                    anchor = curr->next;
                sum = 0;
            } else {
                sum += curr->val;
            }

            prev = curr;
            curr = curr->next;
        }
        prev->next = nullptr;

        return head->next;
    }
};