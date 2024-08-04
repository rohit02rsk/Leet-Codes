public class Solution {
    public int RangeSum(int[] nums, int n, int left, int right) {
        int MOD = 1000000007;
        int[] subArray = new int[(n * (n + 1)) / 2];
        int idx = 0;
        for (int i = 0; i < nums.Length; i++) {
            int currentSum = 0;
            for (int j = i; j < nums.Length; j++) {
                currentSum += nums[j];
                subArray[idx++] = currentSum;
            }
        }
        Array.Sort(subArray);
        int sum = 0;
        for (int i = left - 1; i < right; i++) {
            sum = (sum + subArray[i]) % MOD;
        }
        return sum;
    }
}