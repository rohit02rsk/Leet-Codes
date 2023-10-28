class Solution {
public:
    int countVowelPermutation(int n) {
        long long mod = 1e9 + 7;
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        long long a_curr, e_curr, i_curr, o_curr, u_curr;
        for (int it=0; it<n-1; it++) {
            a_curr = (e + i + u) % mod;
            e_curr = (a + i) % mod;
            i_curr = (e + o) % mod;
            o_curr = i % mod;
            u_curr = (i + o) % mod;
            a = a_curr;
            e = e_curr;
            i = i_curr;
            o = o_curr;
            u = u_curr;
        }
        return (a + e + i + o + u) % mod;
    }
};