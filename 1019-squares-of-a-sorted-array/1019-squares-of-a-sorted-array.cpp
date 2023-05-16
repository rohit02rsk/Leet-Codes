class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mid;
        int low = 0;
        int high = nums.size()-1;
        int i = high;
        vector<int> res(i+1);
        while(low <= high) {
            int n1 = nums[low]*nums[low];
            int n2 = nums[high]*nums[high];
            if(n1 > n2) {
                res[i] = n1;
                i--;
                low++;
            } else {
                res[i] = n2;
                i--;
                high--;
            }
        }
        return res;
    }
};