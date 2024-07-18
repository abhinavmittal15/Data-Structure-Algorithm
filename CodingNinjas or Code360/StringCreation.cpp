//Link : https://www.naukri.com/code360/contests/weekly-contest-135/14164533/problems/32746?leftPanelTabValue=PROBLEM

#include <iostream>
#include<string>
using namespace std;

int getMinimumCost(int n, string &s) {
    int count = 0;
    char currChar = s[0];
    for(int i=1; i<n; i++){
        if (s[i] != currChar) {
            count++;
            currChar = s[i];
        }
    }
    return count;
}


int main(){
    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << getMinimumCost(n, s) << endl;
    }
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)

i/p : 
2
3
010
2
11

*/
