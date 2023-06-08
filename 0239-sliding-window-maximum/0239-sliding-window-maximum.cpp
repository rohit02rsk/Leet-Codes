class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        int n = nums.size();
        for(int i=0; i<k; i++) {
            while(!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.emplace_back(i);
        }
        for(int i=k; i<n; i++) {
            res.emplace_back(nums[dq.front()]);
            while(!dq.empty() and dq.front() <= i-k)
                dq.pop_front();
            while(!dq.empty() and nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.emplace_back(i);
        }
        res.emplace_back(nums[dq.front()]);
        return res;
    }
};