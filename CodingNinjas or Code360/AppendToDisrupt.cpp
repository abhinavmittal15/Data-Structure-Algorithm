// Link : https://www.naukri.com/code360/contests/weekly-contest-133/13846707/problems/32591?leftPanelTabValue=SUBMISSION

#include<iostream>
#include<vector>

using namespace std;

int canYouDisrupt(int n, vector<int> &arr) {
    if(n < 2) return -1;
    int lastElem = arr[n-1];
    for (int i = n-2; i >= 0; i--) {
        if(arr[i] < lastElem){
            return arr[i];
        }
    }
    return -1;    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        cout << canYouDisrupt(n, arr) << endl;
    }
    return 0;
}