public class Solution {
    public String reverseWords(String s) {
        String[] arr = s.trim().split("\\s+");
        int i= 0;
        int j = arr.length - 1;
        while(i < j){
            String temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        return String.join(" ", arr);
    }
    public static void main (String[] args) {
        Solution obj = new Solution();
        String s = "the sky is blue";
        System.out.println(obj.reverseWords(s));
    }
}
