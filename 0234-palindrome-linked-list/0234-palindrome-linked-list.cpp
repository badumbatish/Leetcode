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
        std::vector<int> comp_vector;
        while (head != nullptr) {
            comp_vector.push_back(head->val);
            head = head->next;
        }

        int left = 0, right = comp_vector.size() - 1;

        while (left < right) {
            if (comp_vector[left++] != comp_vector[right--]) return false;
        }

        return true;
    }
};