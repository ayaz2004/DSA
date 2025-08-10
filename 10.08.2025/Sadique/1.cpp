/*
Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.
The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   bool canBeIncreasing(vector<int>& nums){
     int prev=nums[0];
     bool f=false;
     for(int i=1; i<nums.size(); i++){
        if(nums[i]<=prev){
            if(f) f=false;
            f=true;
            if(i==1 || nums[i]>nums[i-1]) prev=nums[i];
        } else prev=nums[i];
     }
     return true;
   }
};

int main(){
   vector<int> nums{1, 2, 10, 5, 7};
   Solution sol;
   bool ans=sol.canBeIncreasing(nums);
   cout<<ans<<endl;
   return 0;
}