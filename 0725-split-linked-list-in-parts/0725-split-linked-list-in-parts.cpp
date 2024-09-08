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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = get_length(head);
        int more = std::ceil(length * 1.0 / k), less = std::floor(length * 1.0 / k);

        std::vector<ListNode*> result;
        while (k) {
            result.push_back(head);
            
            if (length % k == length) {
                head = take(head, 1);
                length -= 1;
            }
            else if (length % k != 0) {
                head = take(head, more);
                length -= more;
            } else {
                head = take(head, less);
                length -= less;
            }
            k--;
        }
        
        return result;
    }

    int get_length(ListNode* head) {
        int count = 0;
        while (head) {
            head = head->next;
            count++;
        }

        return count;
    }

    // Takes "length" notes away by marking its end as nullptr 
    // returning the new section
    ListNode* take(ListNode* head, int length) {
        if (!head) return nullptr;
        while (length != 1 && head->next) {
            length--;
            head = head->next;
        }
        auto n = head->next;
        head->next = nullptr;
        return n;
    }
};