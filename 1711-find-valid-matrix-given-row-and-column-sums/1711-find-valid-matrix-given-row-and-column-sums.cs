public class Solution {
    public int[][] RestoreMatrix(int[] rowSum, int[] colSum) {
        int m = rowSum.Length;
        int n = colSum.Length;
        int[][] res = new int[m][];
        int rpt = 0;
        int cpt = 0;
        
        for(int i=0; i<m; ++i)
            res[i] = new int[n];

        while (rpt<m && cpt<n) {
            var val = Math.Min(rowSum[rpt], colSum[cpt]);
            res[rpt][cpt] = val;

            if (val == rowSum[rpt]) {
                for(int i = cpt + 1; i < n; i++)
                    res[rpt][i] = 0;
                
                colSum[cpt] -= val;
                rpt++;
            } 
            else {
                for(int i = rpt + 1; i < m; i++)
                    res[i][cpt] = 0;
                
                rowSum[rpt] -= val;
                cpt++;
            }
        }

        return res;
    }
}