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
    bool isPalindrome(ListNode* head) {
        std::vector<int> vect;
        while (head) {
            vect.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = vect.size() - 1;
        while (left < right) {
            if (vect[left++] != vect[right--]) return false;
        }
        return true;
    }
};