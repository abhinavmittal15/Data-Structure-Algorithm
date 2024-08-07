#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution { 
public:
    string reversePrefix(string word, char ch){

        size_t index = word.find(ch);

        if(index != string::npos)
            reverse(word.begin(), word.begin() + index + 1);
        
        return word;
    }
};

int main(){
    Solution s;
    string word = "abcdefd";
    char ch = 'd';
    cout << s.reversePrefix(word, ch) << endl;
    return 0;
}