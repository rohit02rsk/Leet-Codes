class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> sortedQueries = queries;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;
        vector<int> res;
        
        sort(intervals.begin(), intervals.end());
        sort(sortedQueries.begin(), sortedQueries.end());
        
        int i = 0;
        for(auto query : sortedQueries) {
            while (i < intervals.size() and intervals[i][0] <= query) {
                int left = intervals[i][0];
                int right = intervals[i][1];
                pq.push({right - left + 1, right});
                i++;
            }

            while (!pq.empty() and pq.top().second < query) 
                pq.pop();
            
            if (!pq.empty()) 
                m[query] = pq.top().first;
            else 
                m[query] = -1;
        }
        
        for (int j = 0; j < queries.size(); j++) 
            res.push_back(m[queries[j]]);
        
        return res;
    }
};