public class Solution {
    public int findMaxIndex(int[][] mat, int n, int m, int mid) {
        int max = Integer.MIN_VALUE;
        int index = 0;
        for(int i=0; i<n; i++){
            if(mat[i][mid] > max){
                max = mat[i][mid];
                index = i;
            }
        }
        return index;
    }
    public int[] findPeakGrid(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int low = 0;
        int high = m-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            int maxRowIndex = findMaxIndex(mat, n, m, mid);
            int left = mid - 1 >= 0 ? mat[maxRowIndex][mid-1] : -1;
            int right = mid + 1 < m ? mat[maxRowIndex][mid+1] : -1;
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right){
                return new int[]{maxRowIndex, mid};
            }    
            else if(mat[maxRowIndex][mid] < left){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return new int[]{-1, -1};
    }
    public static void main(String[] args) {
        Solution obj = new Solution();
        int[][] mat = {{1, 4}, {3, 2}};
        int[] peak = obj.findPeakGrid(mat);
        System.out.println("[" + peak[0] + "," + peak[1] + "]");
    }
}
