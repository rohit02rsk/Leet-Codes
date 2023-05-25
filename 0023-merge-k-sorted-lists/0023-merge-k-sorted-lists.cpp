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
    struct compare {
        bool operator() (const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }  
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto list : lists)
            if(list) pq.emplace(list);
        if(pq.empty()) return NULL;
        
        ListNode* res = pq.top();
        pq.pop();
        if(res->next) pq.emplace(res->next);
        
        ListNode* rest = res;
        while(!pq.empty()) {
            rest->next = pq.top();
            pq.pop();
            rest = rest->next;
            if(rest->next) pq.emplace(rest->next);
        }
        return res;
    }
};