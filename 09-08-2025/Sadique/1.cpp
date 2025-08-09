/*
A split of an integer array is good if:
The array is split into three non-empty contiguous subarrays - named left, mid, right respectively from left to right.
The sum of the elements in left is less than or equal to the sum of the elements in mid, and the sum of the elements in mid is less than or equal to the sum of the elements in right.
Given nums, an array of non-negative integers, return the number of good ways to split nums. As the number may be too large, return it modulo 109 + 7.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int waysToSplit(vector<int>& nums){
    int mod=1e9+7;
    int n=nums.size();
    vector<int> pre_sum(n+1, 0);
    long long ans=0;
    for(int i=0; i<n; i++) pre_sum[i+1]=pre_sum[i]+nums[i];
    for(int i=0; i<n-2; i++){
       long long left_sum=pre_sum[i+1];
       int l=lower_bound(pre_sum.begin()+i+2, pre_sum.end()-1, 2*left_sum)-pre_sum.begin();
       int h=upper_bound(pre_sum.begin()+i+2, pre_sum.end()-1, (pre_sum[n]+left_sum)/2)-pre_sum.begin()-1;
       if(l<=h) ans=(ans+(h-l+1))%mod;
    }
    return ans;
   }
};

int main(){
    vector<int> nums1{1,2,2,2,5,0};
    vector<int> nums2{3,2,1};
    Solution sol;
    int ans1=sol.waysToSplit(nums1);
    int ans2=sol.waysToSplit(nums2);

    cout<<ans1<<endl<<ans2<<endl;
    return 0;

}