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
    ListNode* sortList(ListNode* head) {
        if(!head or !head->next) return head;
        
        //get the middle
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr and curr->next) {
            prev = (prev == NULL) ? head : prev->next;
            curr = curr->next->next;
        }
        ListNode* mid = prev->next;
        prev->next = NULL;
        
        ListNode* l = sortList(head);
        ListNode* r = sortList(mid);
        return merge(l, r);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode temp = ListNode(0);
        ListNode* ptr = &temp;
        while(l1 and l2) {
            if(l1->val < l2->val) {
                ptr->next = l1;
                l1 = l1->next;
            }
            else {
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if(l1) ptr->next = l1;
        else ptr->next = l2;
        return temp.next;
    }
};