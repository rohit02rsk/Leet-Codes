class Solution {
public:
    bool isUgly(int n) {
        vector<int> primes = {2, 3, 5};
        if (n < 1) return false;
        for (int p: primes) while (n % p == 0) n /=p;
        return n == 1;
    }
};