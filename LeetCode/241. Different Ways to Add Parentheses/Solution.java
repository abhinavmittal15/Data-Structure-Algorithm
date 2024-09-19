import java.util.ArrayList;
import java.util.List;

public class Solution {
    public List<Integer> diffWaysToCompute(String expression) {
        List<Integer> res = new ArrayList<Integer>();
        for(int i=0; i<expression.length(); i++) {
            char c = expression.charAt(i);
            if(c == '-' || c == '+' || c == '*') {
                String a = expression.substring(0, i);
                String b = expression.substring(i+1);
                List<Integer> al = diffWaysToCompute(a);
                List<Integer> bl = diffWaysToCompute(b);
                for(int x : al) {
                    for(int y : bl) {
                        if(c == '-') {
                            res.add(x-y);
                        }
                        else if(c == '+') {
                            res.add(x+y);
                        }
                        else if(c == '*') {
                            res.add(x*y);
                        }
                    }
                }
            }
        }
        if(res.size() == 0) {
            res.add(Integer.valueOf(expression));
        }
        return res;
    }
    public static void main(String[] args) {
        Solution obj = new Solution();
        String expression = "2*3-4*5";
        List<Integer> res = obj.diffWaysToCompute(expression);
        for(int r : res) {
            System.out.print(r+ " ");
        }
    }
}