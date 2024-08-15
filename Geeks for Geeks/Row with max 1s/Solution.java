class Solution{
    public int rowWithMax1s(int arr[][]){
        int n = arr.length;
        int m = arr[0].length;
        int maxCount = 0;
        int rowIndex = -1;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1){
                    count++;
                }
            }
            if(count > maxCount){
                maxCount = count;
                rowIndex = i;
            }
        }
        return rowIndex;
    }
    public static void main(String[] args){
        int arr[][] = {{0, 1, 1, 1},
                       {0, 0, 1, 1},
                       {1, 1, 1, 1},
                       {0, 0, 0, 0}};
        Solution obj = new Solution();
        System.out.println(obj.rowWithMax1s(arr));
    }
}