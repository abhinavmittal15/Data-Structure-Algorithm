class Solution{
    public int rowWithMax1s(int arr[][]){
        int n = arr.length;
        int m = arr[0].length;
        int r = 0;
        int c = m -1;
        int rowIndex = -1;
        
        while(r < n && c >= 0){
            if(arr[r][c] == 1){
                rowIndex = r;
                c--;
            }
            else{
                r++;
            }
        }
        return rowIndex;
    }
    public static void main(String[] args){
        int arr[][] = {{0, 1, 1, 1},{0, 0, 1, 1},{1, 1, 1, 1},{0, 0, 0, 0}};
        Solution obj = new Solution();
        System.out.println(obj.rowWithMax1s(arr));
    }
}