import java.util.Arrays;

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        int[] temp = Arrays.copyOf(piles, n);
        Arrays.sort(temp);        
        int s = 1;
        int e = temp[n-1];
        int ans = Integer.MAX_VALUE;
        while(s <= e){
            int m = s + (e - s)/2;
            int time = requiredTime(piles, m);
            if(time <= h){
                ans = m;
                e = m - 1;
            }
            else{
                s = m + 1;
            }
        }
        return ans;
    }
    private int requiredTime(int[] arr, int speed){
        int totalHours = 0;
        for(int i=0; i<arr.length; i++){
            totalHours += Math.ceil((double) arr[i]/speed);
            // totalHours += (int) Math.ceil((double) arr[i]/speed);
        }
        return totalHours;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] piles = {805306368,805306368,805306368};
        int h = 1000000000;
        System.out.println(sol.minEatingSpeed(piles, h));
    }
}