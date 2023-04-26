class Solution {
public:
    int addDigits(int num) {
        // while (num > 9) {
        //     int temp = num;
        //     int sum = 0;
        //     while(temp > 0) {
        //         sum += temp%10;
        //         temp /= 10;
        //     }
        //     num = sum;
        // }
        // return num;
        if(num == 0) return 0;
        else if(num%9 == 0) return 9;
        else return num%9;
    }
};