class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int pd = 0;
        for(int i=0; i<arr.size()-1; i++) {
            if(i != 0 and pd != arr[i+1] - arr[i]) return false;
            pd = arr[i+1] - arr[i];
        }
        return true;
    }
};