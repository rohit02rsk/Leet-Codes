class Solution {
public:
    int arrangeCoins(long long int n) {
        long long int low = 1;
        long long int high = n;
        long long int mid;
        int res = 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            long long int sum = mid*(mid+1)/2;
            if(sum > n) {
                high = mid - 1;
            } 
            else if (sum == n) return mid;
            else {
                res = mid;
                low = mid + 1;
            }
        }
        return res;
    }
};