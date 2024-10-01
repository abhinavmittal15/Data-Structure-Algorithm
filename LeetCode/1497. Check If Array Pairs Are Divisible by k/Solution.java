class Solution {
    public boolean canArrange(int[] arr, int k) {
        int[] remainderCount = new int[k];
        for(int i : arr) {
            int remainder = ((i % k) + k) % k;
            remainderCount[remainder]++;
        }
        for(int i=1; i<=k/2; i++) {
            if(remainderCount[i] != remainderCount[k-1]) {
                return false;
            }
        }
        return remainderCount[0] % 2 == 0;
    }
    public static void main(String[] args) {
        Solution obj = new Solution();
        int[] arr = {1, 2, 3, 4, 5, 10, 6, 7, 8, 9};
        int k = 5;
        System.out.println(obj.canArrange(arr, k));
    }
}