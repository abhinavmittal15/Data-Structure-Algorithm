#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {
            if (s[start] != s[end]) {
                break;
            }

            char currentChar = s[start];
            while (start <= end && s[start] == currentChar) {
                start++;
            }

            while (start <= end && s[end] == currentChar) {
                end--;
            }
        }

        return end - start + 1;
    }
};

int main() {
    Solution s;
    cout << s.minimumLength("aabccabba");
    return 0;
}