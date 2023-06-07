class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& arr) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<arr.size(); i++) 
            adj[arr[i][0]].push_back(arr[i][1]);
        
        unordered_set<int> vis;
        for(int i=0; i<n; i++) {
            if(!dfs(i, adj, vis))
                return false;
        }
        return true;
    }
    bool dfs(int source, unordered_map<int, vector<int>> &adj, unordered_set<int> &vis) {
        if(vis.find(source) != vis.end())
            return false;
        
        auto nbr = adj[source];
        if(nbr.empty())
            return true;
        
        vis.insert(source);
        
        for(int i=0; i<nbr.size(); i++) 
            if(!dfs(nbr[i], adj, vis))
                return false;

        adj[source] = {};
        vis.erase(source);
        return true;
    }
};