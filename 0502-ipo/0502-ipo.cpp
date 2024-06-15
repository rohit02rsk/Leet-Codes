class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>> pq; // [profit, -capital]
        for (int i = 0; i < profits.size(); i++)
            pq.push({profits[i], -capital[i]});
        while (k--) {
            vector<pair<int, int>> v;
            
            while (!pq.empty() and -pq.top().second > w)
                v.push_back(pq.top()), pq.pop();
            
            if (pq.empty()) return w;
            
            auto [prof, cap] = pq.top();
            pq.pop();
            w += prof;
            
            for (auto x : v) pq.push(x);
        }
        return w;
    }
};