class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        unordered_set<int> vis;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > minHeap;
        int res = 0;
        for(int i=0; i<times.size(); i++) 
            adj[times[i][0]].push_back({times[i][2], times[i][1]}); // u -> [ {time, v}.. ]
        
        minHeap.push({0, k});
        while(vis.size() < n and !minHeap.empty()) {
            auto [cost, curr] = minHeap.top();
            minHeap.pop();
            
            if(vis.count(curr)) 
                continue; 
            
            res = max(res, cost);
            vis.insert(curr);
            for(auto [nbr_cost, nbr] : adj[curr]) {
                minHeap.push({cost + nbr_cost, nbr});
            }
        }

        return vis.size() == n ? res : -1;
    }
};