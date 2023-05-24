class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> temp;
        for (int i=0; i<points.size(); i++) 
            temp.push_back({points[i][0]*points[i][0] + points[i][1]*points[i][1], i});
        
        priority_queue < vector<int>, vector<vector<int>>, greater<vector<int>> > pq(temp.begin(), temp.end());
        
        vector<vector<int>> res;
        for(int i=0; i<k; i++) {
            res.push_back(points[pq.top()[1]]);
            pq.pop();
        }
        return res;
    }
};