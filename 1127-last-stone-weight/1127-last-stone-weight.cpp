class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones) pq.push(i);
        while(pq.size() > 1) {
            int st1 = pq.top();
            pq.pop();
            int st2 = pq.top();
            pq.pop();
            pq.push(st1 - st2);
        }
        return pq.top();
    }
};