/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   vector<int> rotate_array(vector<int>& nums, int k){
      int n=nums.size();
      vector<int> ans(n);
      for(int i=0; i<n; i++){
        ans[i]=nums[(i+k)%n];
      }
      return ans;
   }
};

int main(){
   vector<int> nums{1, 2, 3, 4, 5, 6, 7};
   int k=3;
   Solution sol;
   vector<int> ans=sol.rotate_array(nums, k);
   for(int& it:ans) cout<<it<<" ";
   cout<<endl;
   return 0;
}