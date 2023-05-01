class Solution {
public:
    double average(vector<int>& salary) {
        int mi=INT_MAX;
        int ma=INT_MIN;
        int n = salary.size();
        double avg = 0;
        
        for(int i=0; i<n; i++) {
            mi = min(salary[i], mi);
            ma = max(salary[i], ma);
            avg += salary[i];
        }
        avg -= (mi+ma);
        avg /= (n-2);
        return avg;
    }
};