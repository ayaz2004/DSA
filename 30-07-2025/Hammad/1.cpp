/*
You are given an integer array nums of size n.
Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.
The bitwise AND of an array is the bitwise AND of all the numbers in it.
A subarray is a contiguous sequence of elements within an array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int longest_subarray_and1(vector<int>& nums){
      int cnt=1;
      for(int i=0; i<nums.size(); i++){
        int sum=nums[i], temp=nums[i];
        for(int j=i; j<nums.size(); j++){
            temp=(temp, (sum&nums[j]));
            if(sum>temp){
                sum=temp;
                cnt=j-i+1;
            }
        }
      }
      return cnt;
   }

   int longest_subarray_and2(vector<int>& nums){
    int max_val=*max_element(nums.begin(), nums.end());
    int len=0, cnt=0;
    for(int it:nums){
        if(it==max_val){
            cnt++;
            len=max(len, cnt);
        }
        else cnt=0;
    }
    return len;
   }
};

int main(){
   vector<int> nums{1, 2, 3, 4};
   Solution sol;
//    int ans=sol.longest_subarray_and1(nums);
//    cout<<"Solution by brute force approach : ";
//    cout<<ans<<endl;

   int ans2=sol.longest_subarray_and2(nums);
   cout<<"Solution by optimal approach : ";
   cout<<ans2<<endl;
   return 0;
}