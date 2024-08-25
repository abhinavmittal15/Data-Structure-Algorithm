// public class Solution {
//     public String nearestPalindromic(String n) {
//         if(n.length() == 1 || "10".equals(n)) {
//             int StringToInt = Integer.parseInt(n);
//             return Integer.toString(StringToInt - 1);
//         }
//         if( "11".equals(n)) return "9";

//         int half = n.length()/2;
//         StringBuilder temp = new StringBuilder();
//         for(int i=0; i<half; i++){
//             temp.append(n.charAt(i));
//         }
//         StringBuilder temp2 = new StringBuilder(temp);
//         if(n.length() % 2 == 1){ //if odd
//             temp2.append(n.charAt(half));
//         }
//         //now we need to reverse temp
//         temp.reverse();
//         temp2.append(temp);
//         return temp2.toString();
//     }
class Solution {
    public String nearestPalindromic(String n) {
        if (n.length() == 1 || "10".equals(n)) {
            int stringToInt = Integer.parseInt(n);
            return Integer.toString(stringToInt - 1);
        }
        if ("11".equals(n)) return "9";

        long num = Long.parseLong(n);
        long smaller = findSmallerPalindrome(num);
        long larger = findLargerPalindrome(num);
        
        if (Math.abs(num - smaller) <= Math.abs(larger - num)) {
            return String.valueOf(smaller);
        } else {
            return String.valueOf(larger);
        }
    }
    
    private long findSmallerPalindrome(long num) {
        if (num <= 10) return num - 1;
        
        String s = String.valueOf(num);
        int len = s.length();
        String left = s.substring(0, (len + 1) / 2);
        long leftNum = Long.parseLong(left);
        
        String palindrome = left + new StringBuilder(left.substring(0, len / 2)).reverse().toString();
        long palindromeNum = Long.parseLong(palindrome);
        
        if (palindromeNum < num) {
            return palindromeNum;
        } else {
            leftNum--;
            left = String.valueOf(leftNum);
            palindrome = left + new StringBuilder(left.substring(0, len / 2)).reverse().toString();
            return Long.parseLong(palindrome);
        }
    }
    
    private long findLargerPalindrome(long num) {
        String s = String.valueOf(num);
        int len = s.length();
        String left = s.substring(0, (len + 1) / 2);
        long leftNum = Long.parseLong(left);
        
        String palindrome = left + new StringBuilder(left.substring(0, len / 2)).reverse().toString();
        long palindromeNum = Long.parseLong(palindrome);
        
        if (palindromeNum > num) {
            return palindromeNum;
        } else {
            leftNum++;
            left = String.valueOf(leftNum);
            palindrome = left + new StringBuilder(left.substring(0, len / 2)).reverse().toString();
            return Long.parseLong(palindrome);
        }
    }
    public static void main(String[] args) {
        Solution obj = new Solution();
        String str = "100";
        System.out.println(obj.nearestPalindromic(str));
    }
}
