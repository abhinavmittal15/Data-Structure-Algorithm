#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int lengthOfLastWord(string s){
        int n = s.size();
        int count = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ' '){
                if(count > 0){
                    return count;
                }
            }
            else{
                count++;
            }
        }
        return count;        
    }
};

int main(){
    Solution obj;
    string s = "Hello World";
    string m = "   fly me   to   the moon  ";
    cout << obj.lengthOfLastWord(s) << endl;
    cout << obj.lengthOfLastWord(m) << endl;
    return 0;
}