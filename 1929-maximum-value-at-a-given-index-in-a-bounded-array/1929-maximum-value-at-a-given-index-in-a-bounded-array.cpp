class Solution {
public:
    long long calcPart(int a, int num) {
        long an = 0, extraOnes = 0;
        long res = 0;
        
        if(num >= a) {
            an = 1;
            extraOnes = num - a;
        } else if(num < a) {
            extraOnes = 0;
            an = a - num + 1;
        }
        
        res = ((an + a) * (a - an + 1)) / 2;
        res += extraOnes;
        return res;
    }
    int help(int max, int i, int n) {
        long long res = calcPart(max-1, i) + calcPart(max, n-i);
        if(res > 1e9)
            return 1e9 + 1;
        return (int) res;
    }
    int maxValue(int n, int index, int maxSum) {
        int low = 1;
        int high = 1e9;
        int mid = 0;
        
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(help(mid, index, n) > maxSum)
                high = mid - 1;
            else if(help(mid + 1, index, n) <= maxSum) {
                low = mid + 1;
            }
            else 
                break;
        }

        return mid;
    }
};