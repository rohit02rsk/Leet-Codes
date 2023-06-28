class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        vector<double> dist(n, 0.0);
        queue<int> q;

        for(int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        q.push(start);
        dist[start] = 1.0;

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto [node, prob] : adj[curr]) {
                double newProb = dist[curr] * prob;
                if(newProb > dist[node]) {
                    dist[node] = newProb;
                    q.push(node);
                }
            }
        }

        return dist[end];
    }
};