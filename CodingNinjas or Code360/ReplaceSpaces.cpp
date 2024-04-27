//The link to the problem: https://www.naukri.com/code360/problems/replace-spaces_1172172

#include<iostream>
#include<string>
using namespace std;

string replaceSpaces(string &str){
    for(int i=0; i<str.length(); i++){
        if (str[i] == ' ') {
            str.replace(i, 1, "@40");
        }
    }
    return str;
}

int main(){
    string str= "Coding Ninjas Is A Coding Platform";
    // getline(cin, str);
    cout<<replaceSpaces(str);
    return 0;
}