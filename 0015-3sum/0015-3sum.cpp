class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        if(n < 3 or nums[0] > 0)
            return {};
        
        for(int i=0; i<n; i++) {
            if(nums[i] > 0)
                return res;

            if(i > 0 and nums[i] == nums[i-1])
                continue;
            
            int low = i+1;
            int high = n-1;
            while(low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if(sum < 0) {
                    low++;
                }
                else if(sum > 0) {
                    high--;
                }
                else {
                    res.push_back({nums[i], nums[low], nums[high]});
                    int last_low = nums[low];
                    int last_high = nums[high];
                    while(low < high and nums[low] == last_low) {
                        low++;
                    }
                    while(low < high and nums[high] == last_high) {
                        high--;
                    }
                }
            }
        }

        return res;
    }
};