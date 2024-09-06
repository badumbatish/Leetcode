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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::set<int> st;
        for (auto &n : nums) st.insert(n);
        ListNode* dummy = new ListNode(0);
        dummy->next= head;
        auto it = dummy;

        while(it->next) {
            if (st.contains(it->next->val)) it->next = it->next->next;
            else it = it->next;
        }
        return dummy->next;
    }
};