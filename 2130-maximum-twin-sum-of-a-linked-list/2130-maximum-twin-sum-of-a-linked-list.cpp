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
    int pairSum(ListNode* head) {
        //find middle 
        ListNode* mid = head;
        ListNode* fast = head;
        while(fast and fast->next) {
            fast = fast->next->next;
            mid = mid->next;
        } 
        
        //reverse 2nd half
        ListNode* prev = NULL;
        while(mid) {
            ListNode* temp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = temp;
        }
        
        //find min element
        int max_sum = INT_MIN;
        while(prev) {
            max_sum = max(max_sum, prev->val+head->val);
            head = head->next;
            prev = prev->next;
        }
        return max_sum;
    }
};