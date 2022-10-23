class Solution {
public:
    int minPartitions(string n) {
        char highest = '0';
        for(char c: n) {
            if(c > highest) highest = c;
        }
        return highest - '0';
    }
};