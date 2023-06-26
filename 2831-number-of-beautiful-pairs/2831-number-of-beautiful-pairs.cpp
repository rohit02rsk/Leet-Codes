class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); i++)
            for(int j=i+1; j<nums.size(); j++)
                if(gcd(nums[j] % 10, to_string(nums[i])[0] - '0') == 1) res++;
        return res;
    }
};