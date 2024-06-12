//Link to problem:- https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) {
        // Step 1: Create a frequency array to store counts of elements from 1 to N.
        vector<int> freq(N + 1, 0);
        
        // Step 2: Count the frequencies of elements in the given array.
        for (int i = 0; i < N; i++) {
            if (arr[i] >= 1 && arr[i] <= N) {
                freq[arr[i]]++;
            }
        }
        
        // Step 3: Update the original array with the frequency counts.
        for (int i = 0; i < N; i++) {
            arr[i] = freq[i + 1];
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, P;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.frequencyCount(arr, N, P);
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}