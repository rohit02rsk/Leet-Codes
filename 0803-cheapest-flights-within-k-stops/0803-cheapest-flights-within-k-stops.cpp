class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj(n, vector<int> (n, -1));
        vector<int> dist(n, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        vector<int> stops(n, INT_MAX);
        
        dist[src] = 0;
        stops[src] = 0;

        for(auto f : flights)
            adj[f[0]][f[1]] = f[2];
        
        pq.push({0, src, 0});
        
        while(!pq.empty()) {
            int cost = pq.top()[0];
            int u = pq.top()[1];
            int st = pq.top()[2];
            pq.pop();

            if(u == dst)
                return cost;
            
            if(st == k + 1)
                continue;

            for(int i=0; i<n; i++) {
                if(adj[u][i] > 0) {
                    int curr = cost;
                    int nbrDist = dist[i];
                    int nbrWt = adj[u][i];

                    int currDist = curr + nbrWt;
                    if(currDist < nbrDist or st + 1 < stops[i]) {
                        pq.push({currDist, i, st + 1});
                        dist[i] = currDist;
                        stops[i] = st;
                    }
                    else if (st < stops[i]) {
                        pq.push({currDist, i, st + 1});
                    }
                    stops[i] = st;
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];      
    }
};