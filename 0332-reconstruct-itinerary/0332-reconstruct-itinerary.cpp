class Solution {
public:
    void dfs(unordered_map<string, multiset<string>>& adj, string source, vector<string>& res) {
        while (!adj[source].empty()) {
            string next = *adj[source].begin();
            adj[source].erase(adj[source].begin());
            dfs(adj, next, res);
        }
        res.emplace_back(source);
    } 
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> adj;
        
        for(auto& t : tickets)
            adj[t[0]].insert(t[1]);
        
        dfs(adj, "JFK", res);
        reverse(res.begin(), res.end());
        return res;
    }
};