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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = list1 ;
        int count = 0;
        while (p && p->next) {
            if (count == a -1 ) break;
            
            count++;
            p = p->next;
        }
        std::cout << p->val << std::endl;

        auto q = p->next;
        p->next = list2;
        std::cout << p->next->val << std::endl;
        count = 0;
        while (q) {
            if (count == b - a + 1) break;
            count++;
            q = q->next;
        }
        while(list2 && list2->next) { list2= list2->next;} 

        list2->next = q;

        return list1;
    }
};