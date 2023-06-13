class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int t0 = target[0];
        int t1 = target[1];
        int t2 = target[2];
        bool b0 = false, b1 = false, b2 = false;
        for(int i=0; i<triplets.size(); i++) {
            auto curr = triplets[i];
            if(curr[0] > t0 or curr[1] > t1 or curr[2] > t2)
                continue;
            else {
                if(curr[0] == t0)
                    b0 = true;
                if(curr[1] == t1)
                    b1 = true;
                if(curr[2] == t2)
                    b2 = true;
            }
        }
        return b0 and b1 and b2;
    }
};