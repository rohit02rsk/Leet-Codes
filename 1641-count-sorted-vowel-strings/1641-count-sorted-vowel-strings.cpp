class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> arr(5, 1);
        int ans = 0;
        while(--n) {
            for(int i=3; i>=0; i--) {
                arr[i] += arr[i+1];
            }
        }
        for(auto x: arr) ans += x;
        return ans;        
    }
};