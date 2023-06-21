class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int res = INT_MAX;
    int n = nums.size();
    int i = 0;
    int curr = 0;
    for(int j=0; j<n; j++) {
      curr += nums[j];
      while(i <= j and curr >= target) {
        res = min(res, j-i+1);
        curr -= nums[i];
        i++;
      }
    }
    return res == INT_MAX ? 0 : res;     
  }
};