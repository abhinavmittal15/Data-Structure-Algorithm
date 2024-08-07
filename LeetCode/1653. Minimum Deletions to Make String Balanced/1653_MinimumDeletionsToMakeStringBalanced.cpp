class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0;
        int countB = 0;
        for(int i=0; i< s.length(); i++){
            if(s[i] == 'b'){
                countB++;
            }
            else if(countB > 0){
                countB--;
                ans++;
            }
        }
        return ans;
    }
};