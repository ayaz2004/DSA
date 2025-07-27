/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void arrange_zeros(vector<int>& nums){
      int n=nums.size(), cnt=0;
      for(int i=0; i<n; i++){
         if(nums[i]!=0){
            swap(nums[cnt], nums[i]);
            cnt++;
         }
      }
   }
};

int main(){
    vector<int> nums{0, 1, 0, 3, 12};
    Solution sol;
    sol.arrange_zeros(nums);
    for(int& it:nums) cout<<it<<" ";
    cout<<endl;
    return 0;
}