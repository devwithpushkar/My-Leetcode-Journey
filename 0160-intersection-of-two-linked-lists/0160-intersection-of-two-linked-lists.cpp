/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        unordered_set<ListNode*> visited;

        while(tempA) {
            visited.insert(tempA);
            tempA = tempA->next;
        }

        ListNode* tempB = headB;
        while(tempB) {
            if(visited.count(tempB)) return tempB;
            tempB = tempB->next;
        }

        return nullptr;
    }
};