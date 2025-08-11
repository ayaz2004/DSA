/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target){
        int n=nums.size();
        int l=0, h=n-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]==target) return m;
            if(nums[l]<=nums[m]){
                if(nums[l]<=target && target<=nums[m]) h=m-1;
                else l=m+1;
            }else{
                if(nums[m]<=target && target<=nums[h]) l=m+1;
                else h=m-1;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target=0;
    Solution sol;

    int ans=sol.search(nums, target);
    cout<<ans<<endl;
    return 0;
}