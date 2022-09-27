class Solution {
public:
    string pushDominoes(string dominoes) {
        int N = dominoes.length();
        vector<int> forces(N, 0);
        int force = 0;
        
        for(int i = 0 ; i < N ; i++) {
            if(dominoes[i] == 'R') {
                force = N;
            } else if(dominoes[i] == 'L') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            forces[i] += force;
        }
        
        force = 0;
        for(int i = N-1 ; i >= 0 ; i--) {
            if(dominoes[i] == 'L') {
                force = N;
            } else if(dominoes[i] == 'R') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            forces[i] -= force;
        }
        
        string res = "";
        for(int i = 0 ; i < N ; i++) {
            if(forces[i] > 0) res += 'R';
            else if(forces[i] < 0) res += 'L';
            else res += '.';
        }
        return res;
    }
};