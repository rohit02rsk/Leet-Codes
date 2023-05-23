class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k1, vector<int>& nums) {
        k = k1;
        for(int i=0; i<nums.size(); i++) {
            if(pq.size() >= k) {
                pq.push(nums[i]);
                pq.pop();
            } 
            else {
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */