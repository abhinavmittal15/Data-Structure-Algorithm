// Link : https://www.naukri.com/code360/problems/search-in-a-rotated-sorted-array-ii_7449547
// Date : 24-July-2024

#include<iostream>
#include<vector>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (nums[m] == target)
        {
            // return m;
            return true;
        }
        if (nums[s] == nums[m] && nums[m] == nums[e])
        {
            s++;
            e--;
        }
        // if terget is not at mid then check for which part is sorted left || right
        if (nums[s] <= nums[m])
        {
            // left part is sorted
            if (nums[s] <= target && target <= nums[m])
            {
                // means target lies in left part, so eliminate right part
                e = m - 1;
            }
            else
            {
                // target doesn't lie in left part, so eliminate left part
                s = m + 1;
            }
        }
        else
        {
            // right part is sorted
            if (nums[m] <= target && target <= nums[e])
            {
                // means target lies in right part, so eliminate left part
                s = m + 1;
            }
            else
            {
                // target doesn't lie in right part, so eliminate right part
                e = m - 1;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    cout << searchInARotatedSortedArrayII(nums, target) << endl;
    return 0;
}