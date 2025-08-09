/*
You are given a 0-indexed array of integers nums.
A prefix nums[0..i] is sequential if, for all 1 <= j <= i, nums[j] = nums[j - 1] + 1. In particular, the prefix consisting only of nums[0] is sequential.
Return the smallest integer x missing from nums such that x is greater than or equal to the sum of the longest sequential prefix.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int missingInteger(vector<int>& nums){
      unordered_set<int> us(nums.begin(), nums.end());
      int ans=nums[0];
      for(int i=1; i<nums.size(); i++){
        if(nums[i-1]+1 == nums[i]) ans+=nums[i];
        else break;
      }
      while(true){
        if(us.count(ans)==0) return ans;
        ans++;
      }
      return ans;
   }
};

int main(){
    vector<int> nums{3, 4, 5, 1, 12, 14, 13};
    Solution sol;
    int ans=sol.missingInteger(nums);
    cout<<ans<<endl;
    return 0;
}