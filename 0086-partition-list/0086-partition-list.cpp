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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(-1);
        ListNode* lessTail = lessHead;
        ListNode* moreHead = new ListNode(-2);
        ListNode* moreTail = moreHead;

        ListNode* temp = head;
        while(temp != nullptr) {
            ListNode* upcoming = temp->next;
            if(temp->val < x) {
                lessTail->next = temp;
                lessTail = temp;
            } else {
                moreTail->next = temp;
                moreTail = temp;
            }
            temp = upcoming;
        }

        moreTail->next = nullptr;   //marks the end of the answer list.

        lessTail->next = moreHead->next;
        return lessHead->next;
    }
};