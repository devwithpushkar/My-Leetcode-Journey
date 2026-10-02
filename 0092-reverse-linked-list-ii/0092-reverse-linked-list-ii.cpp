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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1); //prevents special cases where we have to reverse head too.
        dummy->next = head;

        ListNode* origin = dummy;   //points to the node just before left.
        ListNode* start;    //points to the left node.
        ListNode* end;      //points to the right node.

        for(int i=1; i < left; i++) {
            origin = origin->next;
        }
        start = origin->next;   //left is an index (not a value)

        ListNode* temp = head;
        for(int i=1; i < right; i++) {
            temp = temp->next;
        }
        end = temp;
        ListNode* after = end->next;

        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = nullptr;
        while(curr != after) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        origin->next = prev;
        start->next = after;

        return dummy->next;
    }
};