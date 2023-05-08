class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector <int> res(n);
        stack < pair <int, int> > st;
        
        for(int i=0; i<n; i++) {
            int day = i;
            int temp = temps[i];
            while(!st.empty() and st.top().second < temp) {
                int prevDay = st.top().first;
                int prevTemp = st.top().second;
                st.pop();
                res[prevDay] = day - prevDay;
            }
            st.push({day, temp});    
        }
        
        
        return res;
    }
};