public class Solution {
    public IList<IList<int>> GetAncestors(int n, int[][] edges) {
        Dictionary<int, List<int>> adj = new(); 
        IList<IList<int>> ans = new List<IList<int>>();
        
        foreach (int[] e in edges) {
            if (!adj.ContainsKey(e[1])) 
                adj[e[1]] = new List<int>();
            adj[e[1]].Add(e[0]);
        }
        
        for (int i = 0; i < n; i++) {
            HashSet<int> vis = new();
            List<int> cur = new();

            dfs(i, adj, vis, cur);
            cur.Sort();
            ans.Add(new List<int>(cur));
        }
        
        return ans; 
    }

    private void dfs(int node, Dictionary<int, List<int>> map, HashSet<int> vis, List<int> cur) {
        vis.Add(node);
        if (!map.ContainsKey(node)) 
            return;

        foreach (int x in map[node]) {
            if (vis.Contains(x)) 
                continue;
            cur.Add(x);
            dfs(x, map, vis, cur);
        }
    }
}