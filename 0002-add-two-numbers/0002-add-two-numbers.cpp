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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* num2) {
        ListNode* num1 = l1;
        ListNode* prev_num1;
        while(num1 or num2) {
            if(num1 and num2) {
                int carry = (num1->val + num2->val) / 10;
                num1->val = (num1->val + num2->val)%10;
                if(carry) {
                    if(num1->next) {
                        num1->next->val += carry;
                    } else {
                        num1->next = new ListNode(carry);
                    }
                }
                prev_num1 = num1;
                num1 = num1->next;
                num2 = num2->next;
            } else if(!num2) {
                while(num1) {
                    int carry = num1->val / 10;
                    num1->val = num1->val % 10;
                    if(carry) {
                        if(num1->next) {
                            num1->next->val += carry;
                        } else {
                            num1->next = new ListNode(carry);
                        }
                    }
                    prev_num1 = num1;
                    num1 = num1->next;
                }
            } else {
                prev_num1->next = num2;
                break;
            }
        }
        return l1;
    }
};