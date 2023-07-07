class Solution {
public:
    int help(string& str, int k, char c) {
        int res = 0;
        int i = 0;
        int c_count = 0;
        for(int j = 0; j < str.size(); j++) {
            if (str[j] == c) c_count++;
            while(c_count > k) {
                if (str[i] == c) c_count--;
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(help(answerKey, k, 'F'), help(answerKey, k, 'T'));
    }
};