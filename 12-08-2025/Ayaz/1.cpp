/*
Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
Return the number of nice sub-arrays.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
   int atMost(vector<int>& nums, int k){
      int l=0, s=0, ans=0;
      for(int e=0; e<nums.size(); e++){
         l+=nums[e]%2;
         while(l>k){
            l-=nums[s]%2;
            s++;
         }
         ans+=e-s+1;
      }
      return ans;
   }
public:
   int numberOfSubarrays1(vector<int>& nums, int k){
     int curr_sum=0, ans=0;
     unordered_map<int, int> um;
     um[curr_sum]=1;
     for(int i=0; i<nums.size(); i++){
      curr_sum+=nums[i]%2;
      if(um.find(curr_sum-k)!=um.end()) ans+=um[curr_sum-k];
      um[curr_sum]++;
     }
     return ans;
   }

   int numberOfSubarrays2(vector<int>& nums, int k){
      return atMost(nums, k)-atMost(nums, k-1);
   }
};
int main(){
   vector<int> nums{1, 1, 2, 1, 1};
   int k=3;
   Solution sol;

   int ans1=sol.numberOfSubarrays1(nums, k);
   cout<<"Answer using brute-force approach is: ";
   cout<<ans1<<endl;;

   int ans2=sol.numberOfSubarrays2(nums, k);
   cout<<"Answer using optimal approach is: ";
   cout<<ans2<<endl;

   return 0;
}