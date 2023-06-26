class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq1, pq2;
        long long res = 0;
        int l = 0;
        int r = costs.size() - 1;
        for(int i=0; i<k; i++) {
            while(pq1.size() < candidates and l <= r) {
                pq1.push({costs[l], l++});
            }
            while(pq2.size() < candidates and l <= r) {
                pq2.push({costs[r], r--});
            }
            int min1 = pq1.size() > 0 ? pq1.top().first : INT_MAX;
            int min2 = pq2.size() > 0 ? pq2.top().first : INT_MAX;
            if(min1 <= min2) {
                res += min1;
                pq1.pop();
            }
            else {
                res += min2;
                pq2.pop();
            }
        }
        return res;
    }
};