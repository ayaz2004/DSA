/*
Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int distinct_bitwise1(vector<int>& arr){
      unordered_set<int> us;
      for(int i=0; i<arr.size(); i++){
        int temp=0;
        for(int j=i; j<arr.size(); j++){
            temp=temp|arr[j];
            us.insert(temp);
        }
      }
      return us.size();
   }

   int distinct_bitwise2(vector<int>& nums){
      unordered_set<int> us;
      set<int> prev;
      for(int it:nums){
        set<int> curr;
        curr.insert(it);
        for(int it1:prev){
            curr.insert(it1|it);
        }
        for(int it2:curr){
            us.insert(it2);
        }
        prev=curr;
      }
      return us.size();
   }
};

int main(){
   vector<int> arr{1, 1, 2};
   Solution sol;

   int ans1=sol.distinct_bitwise1(arr);
   cout<<"Solution by brute force approach is : ";
   cout<<ans1<<endl;

   int ans2=sol.distinct_bitwise2(arr);
   cout<<"Solution by optimal approach is : ";
   cout<<ans2<<endl;

   return 0;
}