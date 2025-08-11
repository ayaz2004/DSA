/*
A peak element is an element that is strictly greater than its neighbors.
Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.
You must write an algorithm that runs in O(log n) time.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  int findPeakElement(vector<int>& nums){
    int n=nums.size();
    if(n==1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[n-1]>nums[n-2]) return n-1;
    int l=1, h=n-2;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
        else if(nums[mid]>nums[mid-1]) l=mid+1;
        else if(nums[mid]>nums[mid+1]) h=mid+1;
        else h=mid+1;
    }
    return -1;
  }
};

int main(){
   vector<int> nums{1, 2, 3, 1};
   Solution sol;
   int ans=sol.findPeakElement(nums);
   cout<<ans<<endl;
   return 0;
}