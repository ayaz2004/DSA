/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int consecutive_ones(vector<int>& nums){
      int cnt=0, ans=0;
      for(int i=0; i<nums.size(); i++){
        if(nums[i]==1){
            cnt++;
            ans=max(ans, cnt);
        }      
        if(nums[i]==0){
            cnt=0;
        }
      }
      return ans;
   }
   
};
int main(){
   vector<int> nums{1, 1, 0, 1, 1, 1};
   Solution sol;
   int ans=sol.consecutive_ones(nums);
   cout<<ans<<endl;
   return 0;
}