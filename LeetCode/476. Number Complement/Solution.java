public class Solution {
    public int findComplement(int num) {
        String binaryString = Integer.toBinaryString(num);
        StringBuilder complementString = new StringBuilder();

        for(int i=0; i<binaryString.length(); i++){
            if(binaryString.charAt(i) == '1') {
                complementString.append('0');
            }
            else{
                complementString.append('1');
            }
        }
        int complement = Integer.parseInt(complementString.toString(), 2);
        return complement;
    }
    public static void main (String[] args) {
        Solution obj = new Solution();
        int num = 5;
        System.out.println(obj.findComplement(num));
    }
}
