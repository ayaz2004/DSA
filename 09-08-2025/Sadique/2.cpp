/*
You are given a 0-indexed integer array nums and an integer threshold.
Find the length of the longest subarray of nums starting at index l and ending at index r (0 <= l <= r < nums.length) that satisfies the following conditions:
nums[l] % 2 == 0
For all indices i in the range [l, r - 1], nums[i] % 2 != nums[i + 1] % 2
For all indices i in the range [l, r], nums[i] <= threshold
Return an integer denoting the length of the longest such subarray.
Note: A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int longestAlternatingSubarray1(vector<int>& nums, int threshold){
      int ans=0, n=nums.size();
      for(int i=0; i<n; i++){
        int cnt=0;
        if((nums[i]%2==0) && (nums[i]<=threshold)){
            cnt=1;
            for(int j=i+1; j<n; j++){
                if((nums[j]%2==nums[j-1]%2) || nums[j]>threshold) break;
                cnt++;
            }
        }
        ans=max(ans, cnt);
      }
      return ans;
   }

   int longestAlternatingSubarray2(vector<int>& nums, int threshold){
       
   }
};

int main(){
   vector<int> nums{3, 2, 5, 4};
   int threshold=5;
   Solution sol;

   int ans1=sol.longestAlternatingSubarray1(nums, threshold);
   cout<<"The answer by brute-force approach is : ";
   cout<<ans1<<endl;
   
   int ans2=sol.longestAlternatingSubarray2(nums, threshold);
   cout<<"The answer by optimal approach is : ";
   cout<<ans2<<endl;

}