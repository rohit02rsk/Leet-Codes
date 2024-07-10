public class Solution {
    public int MinOperations(string[] logs) {
        var res = 0;
        foreach (var log in logs) {
            if (log.Equals("../")) 
                res -= res == 0 ? 0 : 1;
            else if (!log.Equals("./")) 
                res += 1;
        }
        return res;
    }
}