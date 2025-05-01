import java.util.Scanner;

public class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int count = 0;
        for(int i=1; i<n; i++) {
            if(nums[i-1] > nums[i]) count++;
        }
        if(nums[n-1] > nums[0]) count++;
        return count<=1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the size of the array: ");
        int n = sc.nextInt();
        int[] nums = new int[n];
        System.out.println("Enter the elements of the array: ");
        for(int i=0; i<n; i++) {
            nums[i] = sc.nextInt();
        }

        Solution obj = new Solution();
        // int[] nums = {3, 4, 5, 1, 2};
        System.out.println(obj.check(nums));
    }
};