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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        int length = 1;
        ListNode *new_head, *tail;

        new_head = tail = head;

        // find the tail and get the length of the list
        while (tail && tail->next) {
            tail = tail->next;
            length++;
        }

        // connect the tail to the head
        tail->next = head;


        // Get the new head index
        int new_head_index = length - k % length;
        for (int i = 0; i < new_head_index; i++) {
            tail = tail->next;
        }
        new_head = tail->next;
        tail->next = nullptr;
        return new_head;
        
    }

};