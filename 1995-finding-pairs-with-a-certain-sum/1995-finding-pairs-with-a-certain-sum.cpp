class FindSumPairs {
private:
    unordered_map<int, int> mp2;
    vector<int> n1, n2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int i : nums2)
            mp2[i]++;
    }
    
    void add(int index, int val) {
        mp2[n2[index]]--;
        n2[index] += val;
        mp2[n2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (int i : n1) {
            if (mp2.count(tot - i))
                res += mp2[tot-i];
        }
        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */