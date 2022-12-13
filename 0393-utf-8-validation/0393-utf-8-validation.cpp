class Solution {
public:
     bool validUtf8(vector<int>& data) {
        int rem = 0;
        for(auto byte: data) {
            if(rem == 0) {
                if((byte>>3) == 0b11110) rem = 3;
                else if((byte>>4) == 0b1110) rem = 2;
                else if((byte>>5) == 0b110) rem = 1;
                else if((byte>>7) == 0) rem = 0;
                else return false;
            }
            else {
                if((byte>>6) != 0b10) return false;
                else --rem;
            }
        }
        
        return rem == 0;
    }
};