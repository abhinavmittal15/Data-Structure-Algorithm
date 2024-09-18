class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        if(original.length != m*n) {
            return new int[0][0];
        }
        int[][] result = new int[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                result[i][j] = original[i* n + j];
            }
        }
        return result;
    }
    public static void main(String[] args) {
        Solution obj = new Solution();
        int[] original = {1, 2, 3, 4};
        int m = 2;
        int n = 2;
        int[][] result = obj.construct2DArray(original, m, n);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }
    }
}