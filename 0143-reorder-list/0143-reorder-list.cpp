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
    void reorderList(ListNode* head) {
        // find mid
        ListNode* half1 = head;
        ListNode* half2 = head; // slow
        ListNode* fast = head->next;
        while(fast and fast->next) {
            half2 = half2->next;
            fast = fast->next->next;
        }

        // reverse 2nd half
        ListNode* curr = half2;
        ListNode* prev = NULL;
        while(curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // merge lists
        half2 = prev;
        while(half1 and half2) {
            ListNode* nxt1 = half1->next;
            ListNode* nxt2 = half2->next;
            half1->next = half2;
            half2->next = nxt1;
            half1 = nxt1;
            half2 = nxt2;
        }
    }
};