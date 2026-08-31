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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        vector<int> ans(2, -1);

        int firstPoint = -1;
        int prevPoint = -1;
        int minDistance = INT_MAX;

        int i = 0;
        while(curr != NULL && curr->next != NULL) {
            if(prev->val < curr->val && curr->val > curr->next->val ||
               prev->val > curr->val && curr->val < curr->next->val) {
                if(firstPoint == -1) firstPoint = i;
                
                if(prevPoint != -1) minDistance = min(minDistance, i - prevPoint);
                
                prevPoint = i;
            }

            prev = curr;
            curr = curr->next;
            i++;
        }
        if(firstPoint != -1 && firstPoint != prevPoint) {
            ans[0] = minDistance;
            ans[1] = prevPoint - firstPoint;
        }

        return ans;
    }
};