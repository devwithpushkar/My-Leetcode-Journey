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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* first;
        ListNode* second;
        ListNode* nextPair;

        while(prev->next && prev->next->next) {
            first = prev->next;
            second = first->next;
            nextPair = second->next;

            prev->next = second;
            second->next = first;
            first->next = nextPair;

            prev = first;
        }
        return dummy->next;
    }
};