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
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr) {
            int sum = carry;
            if(l1 != nullptr && l2 != nullptr) {
                sum += l1->val + l2->val;
            } else if(l1 != nullptr) {
                sum += l1->val;
            } else {
                sum += l2->val;
            }

            int result_digit = sum % 10;

            curr->next = new ListNode(result_digit);
            curr = curr->next;

            carry = sum / 10;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }

        if(carry != 0) {
            curr->next = new ListNode(carry);
            curr = curr->next;
        }

        ListNode* head = dummy->next;
        return head;
    }
};