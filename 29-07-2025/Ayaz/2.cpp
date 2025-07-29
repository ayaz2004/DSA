/*
There are n apples with known weights. Your task is to divide the apples into two groups so that 
the difference between the weights of the groups is minimal. 
*/

#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& nums){
    int n=nums.size();
    long long min_diff=LLONG_MAX;
    int total_sum=accumulate(nums.begin(), nums.end(), 0LL);
    for(int mask=0; mask<(1<<n); mask++){
         long long group_sum1=0;
         for(int i=0; i<n; i++){
            if(mask&(1<<i)) group_sum1+=nums[i];
         }
         long long group_sum2=total_sum-group_sum1;                                                                                               
         long long diff=abs(group_sum1-group_sum2); 
         min_diff=min(min_diff, diff);
        }         
        return min_diff;                                
    }

int main(){
    int n=5;
    vector<int> nums{3, 2, 7, 4, 1};
    long long ans=solve(nums);
    cout<<ans<<endl;
    return 0;
}