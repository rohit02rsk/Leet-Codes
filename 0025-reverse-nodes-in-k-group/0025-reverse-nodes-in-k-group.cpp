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
    ListNode* getKthNode(ListNode* curr, int k) {
        while(curr and k--) curr = curr->next;
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* grpPrev = dummy;
        while (1) {
            ListNode* kth = getKthNode(grpPrev, k);
            if(!kth) return dummy->next;
            ListNode* grpNext = kth->next;
            
            // reverse the group
            ListNode* prev = kth->next;
            ListNode* curr = grpPrev->next;
            while(curr != grpNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = grpPrev->next;
            grpPrev->next = kth;
            grpPrev = temp;
        }
        return NULL;
    }
};