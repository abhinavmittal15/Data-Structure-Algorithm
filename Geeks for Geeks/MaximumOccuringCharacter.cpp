//The link to the problem: https://www.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    char getMaxOccuringChar(string str){
        int count[256] = {0};
        int max = -1;
        for(int i=0; i < str.length(); i++){
            count[str[i]]++;
        }
        
        char result = 'z';
        for(int i=0; i<str.length(); i++){
            count[str[i]]++;
        }

        for(int i=0; i<str.length(); i++){
            if(max < count[str[i]]){
                max = count[str[i]];
                result = str[i];
            }
        }
        return result;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str = "testsample";
        Solution ob;
        cout<<ob.getMaxOccuringChar(str)<<endl;
    }
    return 0;
}