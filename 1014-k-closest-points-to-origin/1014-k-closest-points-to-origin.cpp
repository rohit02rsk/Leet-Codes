class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<double, pair<int, int>>, vector <pair<double, pair<int, int>>>, greater <pair<double, pair<int, int>>> > pq;
        vector<vector<int>> res;
        for(auto pt : points) {
            int x = pt[0], y = pt[1];
            double dist = sqrt(x*x + y*y);
            pq.push({dist, {x, y}});
        }
        while(k--) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};