class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> res, out(n), safe(n);
        queue<int> q;
        for(int i=0; i<n; i++) {
            for(int v : graph[i])
                rev[v].push_back(i);
            out[i] = graph[i].size();
            if(out[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            safe[u] = 1;
            for(int v : rev[u]) 
                if(--out[v] == 0) q.push(v);
        }
        for(int i=0; i<n; i++) if (safe[i]) res.push_back(i);
        return res;
    }
};