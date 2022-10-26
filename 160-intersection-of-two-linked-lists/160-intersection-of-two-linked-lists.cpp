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
        ListNode* tempB = headB;
        
        unordered_set<ListNode*> s;
        
        while(tempA) {
            s.insert(tempA);
            tempA = tempA->next;
        }
        
        while(tempB) {
            if(s.find(tempB) != s.end()) return tempB;
            tempB = tempB->next;
        }
        
        return NULL;
    }
};