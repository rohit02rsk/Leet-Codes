class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long res = 0, curr = 0;
        int n = nums1.size();
        
        vector<pair<int, int>> arr;
        for(int i=0; i<n; i++) arr.push_back({nums2[i], nums1[i]});
        sort(rbegin(arr), rend(arr));
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto &[n2, n1] : arr) {
            pq.emplace(n1);
            curr += n1;
            if(pq.size() > k) {
                curr -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) {
                res = max(res, curr*n2);
            }
        }
        
        return res;
    }
};