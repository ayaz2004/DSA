/*
You are given an array nums consisting of positive integers.
We call a subarray of an array complete if the following condition is satisfied:
The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.
A subarray is a contiguous non-empty part of an array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int countCompleteSubarrays(vector<int>& nums){
     int ans=0, n=nums.size(), left=0, right=0;
     unordered_map<int, int> cnt;
     unordered_set<int> distinct(nums.begin(), nums.end());
     int distinct_cnt=distinct.size();
     while(left<n){
        if(left>0){
            int temp1=nums[left-1];
            cnt[temp1]--;
            if(cnt[temp1]==0) cnt.erase(temp1);
        }
        while(right<n && cnt.size()<distinct_cnt){
            int temp2=nums[right];
            cnt[temp2]++;
            right++;
        }
        if(cnt.size()==distinct_cnt) ans+=(n-right+1);
        left++;
     }
     return ans;
   }
};
int main(){
    vector<int> nums{1, 3, 1, 2, 2};
    Solution sol;
    int ans=sol.countCompleteSubarrays(nums);
    cout<<ans<<endl;
    return 0;
}