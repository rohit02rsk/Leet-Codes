class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        int n = nums.size();
        
        if(n < 3  || nums[0] > 0) return {};        
        
        for(int i=0 ; i<n ; i++) {
            if(nums[i] > 0)
                break;
            
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int low = i+1;
            int high = n-1;
            int sum = 0;     
            
            while(low < high) {
                sum = nums[i] + nums[low] + nums[high];
                if(sum < 0) {
                    low++;
                }
                else if(sum > 0) {
                    high--;
                }
                else {
                    res.push_back({nums[i] , nums[low] , nums[high]});
                    int last_low = nums[low], last_high = nums[high];
                    while(low < high && last_low == nums[low]) low++;
                    while(low < high && last_high == nums[high]) high--;
                }
            }
        }
        return res;
    }
};