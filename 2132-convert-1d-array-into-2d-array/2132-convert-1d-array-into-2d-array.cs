public class Solution {
    public int[][] Construct2DArray(int[] original, int m, int n) {
        if (m * n != original.Length)
            return new int[0][];

        var result = new int[m][];
        for (int i = 0; i < m; i++) {
            result[i] = new int[n];

            for (int j = 0; j < n; j++)
                result[i][j] = original[i * n + j];
        }

        return result;    
    }
}