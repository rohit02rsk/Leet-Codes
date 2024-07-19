public class Solution {
    public IList<int> LuckyNumbers (int[][] matrix) {
        var result = new List<int>();
        for (int i = 0; i < matrix.Length; i++) {
            int rowMin = matrix[i][0];
            int currentCol = 0;
            for (int j = 0; j < matrix[i].Length; j++) {
                if (matrix[i][j] < rowMin) {
                    rowMin = matrix[i][j];
                    currentCol = j;
                }
            }

            int colMax = int.MinValue;
            for (int row1=0; row1<matrix.Length; row1++)
                if (matrix[row1][currentCol] > colMax)
                    colMax = matrix[row1][currentCol];

            if (rowMin == colMax)
                result.Add(rowMin);
        }
        return result;
    }
}