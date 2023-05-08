class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vec;
        stack<pair<int, int>> st;
        int n = speed.size();
        for(int i=0; i<n; i++) {
            vec.push_back(make_pair(position[i], speed[i]));
        }
        sort(vec.begin(), vec.end());
        
        for(int i=n-1; i>=0; i--) {
            if(st.empty()) {
                st.push(vec[i]);
            } else {
                auto x = st.top();
                int pos = x.first;
                int spd = x.second;
                float t1 = (float) (target-pos)/spd;
                float t2 = (float) (target-vec[i].first)/vec[i].second;
                if(t1 < t2) {
                    st.push(vec[i]);
                }
            }
        }
        
        return st.size();
    }
};