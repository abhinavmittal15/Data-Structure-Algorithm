class Solution {
    public int nthUglyNumber(int n) {
        int[] arr = new int[n];
        arr[0] = 1;
        int a=0, b=0, c=0;
        for(int i=1; i<n; i++) {

            arr[i] = Math.min(arr[a] * 2, Math.min(arr[b] * 3, arr[c] * 5));

            if(arr[i] == arr[a] * 2){
                a++;
            }
            if(arr[i] == arr[b] * 3){
                b++;
            }
            if(arr[i] == arr[c] * 5){
                c++;
            }
        }
        return arr[n-1];
    }
    public static void main(String[] args){
        Solution obj = new Solution();
        int n = 10;
        System.out.println(obj.nthUglyNumber(n));
    }
};