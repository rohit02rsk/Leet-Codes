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
    bool isPalindrome(ListNode* head) {
        //first find the middle of the LL
        ListNode* mid = head;
        ListNode* fast = head;
        while(fast and fast->next) {
            mid = mid->next;
            fast = fast->next->next;
        }
        
        //reverse the second half of the LL
        ListNode* prev = NULL;
        while(mid) {
            ListNode* temp = mid->next;
            mid->next = prev;
            prev = mid;
            mid = temp;
        }
        
        //check palindrome
        while(prev) {
            if(prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};