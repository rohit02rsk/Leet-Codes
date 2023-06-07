class Solution {
public:
    int minFlips(int a, int b, int c) {
        const int n = 32;
        string bin_a = std::bitset<n>(a).to_string();
        string bin_b = std::bitset<n>(b).to_string();
        string bin_c = std::bitset<n>(c).to_string();
        int res = 0;
        for(int i=0; i<n; i++) {
            if(bin_c[i] == '1') {
                if(bin_a[i] == '1' or bin_b[i] == '1')
                    continue;
                else res++;
            }
            else if(bin_c[i] == '0') {
                if(bin_a[i] == '1')
                    res++;
                if(bin_b[i] == '1')
                    res++;
            }
        }
        return res;
    }
};