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
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* currA = a;
        ListNode* currB = b;
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(currA != nullptr && currB != nullptr) {
            if(currA->val > currB->val) {
                tail->next = currB;
                tail = tail->next;
                currB = currB->next;
            } else {
                tail->next = currA;
                tail = tail->next;
                currA = currA->next;
            }            
        }

        while(currA != nullptr) {
            tail->next = currA;
            tail = tail->next;
            currA = currA->next;
        }

        while(currB != nullptr) {
            tail->next = currB;
            tail = tail->next;
            currB = currB->next;
        }
        return dummy->next; 
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return merge(left, right);
    }
};