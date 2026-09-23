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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            n++;
            temp = temp->next;
        }

        if(n == 0 || k == n || k == 0) return head;
        if(k > n) k %= n;

        ListNode* slow = head;
        ListNode* fast = head;

        for(int i=0; i < k; i++) {
            fast = fast->next;
        }

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = nullptr;

        return head;
    }
};