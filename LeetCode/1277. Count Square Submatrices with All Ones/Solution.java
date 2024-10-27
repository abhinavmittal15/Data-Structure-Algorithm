import java.util.Scanner;

public class Solution {
    public int countSquares(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int[][] dp = new int[n][m];
        // vector<vector<int>> dp(n, vector<int>(m ,0));
        for(int i=0; i<n; i++) {
            dp[i][0] = matrix[i][0];
        }
        for(int j=0; j<m; j++) {
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][j] == 0) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = 1 + Math.min(dp[i-1][j], Math.min(dp[i-1][j-1], dp[i][j-1]));
                }
            }
        }
        int sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                sum += dp[i][j];
            }
        }
        return sum;
    }
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the no of rows: ");
        int n = scanner.nextInt();
        System.out.println("Enter the no of cols: ");
        int m = scanner.nextInt();

        int[][] matrix = new int[n][m];
        System.out.println("Enter the matrix elem rows by row: ");
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }   
        
        //now the matrix = {{0, 1, 1, 1}, 
                        //  {1, 1, 1, 1}, 
                        //  {0, 1, 1, 1}}
        Solution obj = new Solution();
        System.out.println(obj.countSquares(matrix));
    }
}