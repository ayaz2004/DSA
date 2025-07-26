/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
 
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
 
Constraints:
•	1 <= nums.length <= 2 * 10^4
•	-1000 <= nums[i] <= 1000
•	-10^7 <= k <= 10^7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public: 
  int total_sub_array_1(vector<int>& nums, int target){
    int ans=0;
     for(int i=0; i<nums.size(); i++){
        int sum=0;
        for(int j=i; j<nums.size(); j++){
            sum+=nums[j];
            if(sum==target) ans++;
        }
     }
     return ans;
  }

  int total_sub_array_2(vector<int>& nums, int target){
    unordered_map<int, int> um;
    um[0]=1;
    int curr_sum=0, cnt=0;
    for(int it:nums){
       curr_sum+=it;
       if(um.find(curr_sum-target)!=um.end()) cnt+=um[curr_sum-target];
       um[curr_sum]++;
    }
    return cnt;
  }
};

int main(){

    vector<int> nums={1, 1, 1};
    int target=2;
    
    Solution sol;

    int ans1=sol.total_sub_array_1(nums, target);
    cout<<"Solution by brute force approach is : ";
    cout<<ans1<<endl;

    int ans2=sol.total_sub_array_2(nums, target);
    cout<<"Solution by optimal approach is : ";
    cout<<ans2<<endl;

    return 0; 

}