#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s2.length() > s1.length()) {
            swap(s1, s2);
        }

        vector<string> arr1;
        vector<string> arr2;
        string temp;
        stringstream ss1(s1);
        while(ss1 >> temp) {
            arr1.push_back(temp);
        }
        stringstream ss2(s2);
        while(ss2 >> temp) {
            arr2.push_back(temp);
        }

        int i =0, j = arr1.size()-1;
        int k = 0, l = arr2.size()-1;
        while(i < arr1.size() && k < arr2.size() && arr1[i] == arr2[k]) {
            i++;
            k++;
        }
        while(l >= k && arr1[j] == arr2[l]) {
            j--;
            l--;
        }
        
        if(l < k) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution obj;
    string s1 = "My name is Haley";
    string s2 = "My Haley";
    cout << obj.areSentencesSimilar(s1, s2) << endl;
    return 0;
}