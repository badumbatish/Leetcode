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
        ListNode* curr = head;

        std::vector<int> vec = {};

        int sum = 0;
        while (curr) {
            if (curr->val == 0) {
                vec.push_back(0);
            } else {
                vec.back() += curr->val;
            }

            curr = curr->next;
        }
        vec.pop_back();

        curr = head;

        int cnt = 0;
        while (curr && cnt < vec.size()) {
            curr->val = vec[cnt];
            cnt++;
            curr = curr->next;
        }

        curr = head;
        cnt = 0;
        while (cnt < vec.size() - 1) {
            curr = curr->next;
            cnt++;
        }
        curr->next = nullptr;

        for (auto i : vec) std::cout << i << " ";

        return head;
    }
};