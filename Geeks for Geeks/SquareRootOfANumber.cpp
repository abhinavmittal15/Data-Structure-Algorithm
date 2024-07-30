// Link : Square root of a number

#include <iostream>
using namespace std;

class Solution{
  public:
    long long int floorSqrt(long long int x){
        if(x < 2){
            return x;
        }
        
        int s = 0;
        int e = x;
        int ans = 1;
        while(s <= e){
            int m = s + (e - s)/ 2;
            if(m*m > x){
                e = m - 1;
            }
            else{
                ans = m;
                s = m + 1;
            }
        }
        return  ans;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int x;
        cin >> x;
        Solution obj;
        cout << obj.floorSqrt(x) << endl;
    }
    return 0;
}