import java.util.Arrays;

class Solution {
    public long dividePlayers(int[] skill) {
        Arrays.sort(skill);
        int n = skill.length;
        int sum = skill[0] + skill[n-1];
        int i=0;
        int j=n-1;
        long ans = 0;
        while(i < j) {
            if(skill[i]+skill[j] != sum) {
                return -1;
            }
            ans += skill[i] * skill[j];
            i++;
            j--;
        }
        return ans;
    }
    public static void main(String[] args) {
        Solution obj = new Solution();
        int[] skill = {3, 2, 5, 1, 3, 4};
        System.out.println(obj.dividePlayers(skill));
    }
}