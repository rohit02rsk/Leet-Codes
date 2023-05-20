class Solution {
public:
    void dfs(string &source, string &destination, unordered_map<string,vector<pair<string,double>>>&graph, unordered_map<string,int>&vis, double &ans, double temp) {
        if(vis.count(source))return;
        vis[source]++;
        if(source==destination) {
            ans=temp;
            return;
        }
        
        for(auto it : graph[source]) {
            dfs(it.first, destination, graph, vis, ans, temp*it.second);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res(queries.size());
        unordered_map<string, vector<pair<string, double>>> g;
        unordered_map<string, int> vis;
        for(int i=0; i<equations.size(); i++) {
            g[equations[i][0]].push_back({equations[i][1], values[i]});
            g[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        for(int i=0; i<queries.size(); i++) {
            string u = queries[i][0];
            string v = queries[i][1];
            double ans = -1.0;
            vis.clear();
            if(g.count(u)) {
                dfs(u, v, g, vis, ans, 1.0);
            }
            res[i] = ans;
        }
        return res;
    }
};