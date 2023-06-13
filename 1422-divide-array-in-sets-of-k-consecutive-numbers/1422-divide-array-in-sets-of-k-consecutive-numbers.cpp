class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k)
            return false;
        map<int, int> mp;
        for(int i : nums) mp[i]++;

        while(!mp.empty()) {
            int f = mp.begin()->first;
            for(int i=0; i<k; i++) {
                if(mp[f] == 0) {
                    return false;
                }
                mp[f]--;
                if(mp[f] == 0) {
                    mp.erase(f);
                }
                f++;
            }
        }

        return true;
    }
};