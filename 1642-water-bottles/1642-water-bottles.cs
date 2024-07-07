public class Solution {
    public int NumWaterBottles(int numBottles, int numExchange) {
        var res = numBottles;
        while (numBottles >= numExchange) {
            res += numBottles / numExchange;
            numBottles = (numBottles / numExchange) + (numBottles % numExchange);
        }
        return res;
    }
}