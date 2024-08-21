class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();
        int count = 0;
        for(final char c : s.toCharArray()){
            if(c == '('){
                count++;
                if(count > 1){
                    ans.append(c);
                }
            }
            else{
                count--;
                if(count > 0)
                    ans.append(c);
            }
        }
        return ans.toString();
    }
    public static void main(String[] args){
        Solution obj = new Solution();
        String s = "(()())(())";
        System.out.println(obj.removeOuterParentheses(s));
    }
}