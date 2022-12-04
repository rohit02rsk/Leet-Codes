class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long int lsum = 0, rsum = 0, n = nums.size();
        for(int i: nums) rsum += i;
        
        int mi = INT_MAX, ind = 0;
        
        for(int i=0; i<n; i++) {
            lsum += nums[i];
            rsum -= nums[i];
            int a = lsum / (i+1);
            int b = (i == n-1) ? 0 : (rsum / (n-i-1));
            
            if(abs(a-b) < mi) {
                mi = abs(a-b);
                ind = i;
            }
        }
        
        return ind;
    }
};