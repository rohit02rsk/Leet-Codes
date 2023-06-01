class Solution {
public:
    bool help(vector<int>& arr, int top, int bottom, int left, int right, int pos) {
        if(pos == arr.size()) {
            if(!top and !bottom and !left and !right)
                return true;
            else 
                return false;
        }
        if(arr[pos] <= top) {
            top -= arr[pos];
            if(help(arr, top, bottom, left, right, pos+1)) return true;
            top += arr[pos];
        }
        if(arr[pos] <= bottom) {
            bottom -= arr[pos];
            if(help(arr, top, bottom, left, right, pos+1)) return true;
            bottom += arr[pos];
        }
        if(arr[pos] <= left) {
            left -= arr[pos];
            if(help(arr, top, bottom, left, right, pos+1)) return true;
            left += arr[pos];
        }
        if(arr[pos] <= right) {
            right -= arr[pos];
            if(help(arr, top, bottom, left, right, pos+1)) return true;
            right += arr[pos];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4) return false;
        int sum = 0;
        for(int i : matchsticks) sum += i;
        if(sum % 4 != 0) return false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return help(matchsticks, sum/4, sum/4, sum/4, sum/4, 0);
    }
};