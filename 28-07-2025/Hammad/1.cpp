/*
You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    bool solve(vector<int>& bloomDays, int mid, int m, int k){
        int n=bloomDays.size();
        int cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(bloomDays[i]<=mid) cnt1++;
            else{
                cnt2+=cnt1/k;
                cnt1=0;
            }
        }
        cnt2+=cnt1/k;
        return cnt2>=m;
    }
public:
   int min_days(vector<int>& bloomDays, int m, int k){
      int n=bloomDays.size();
      if((m*1LL)*(k*1LL)>n) return -1;
      int min_val=INT_MAX, max_val=INT_MIN;
      for(int i=0; i<n; i++){
        min_val=min(min_val, bloomDays[i]);
        max_val=max(max_val, bloomDays[i]);
      }
      int l=min_val, h=max_val;
      while(l<=h){
        int mid=(l+(h-l)/2);
        if(solve(bloomDays, mid, m, k)) h=mid-1;
        else l=mid+1;
      }
      return l;
   }
};

int main(){
    int m=3, k=1;
    vector<int> bloomDays{1, 10, 3, 10, 2};
    Solution sol;
    int ans=sol.min_days(bloomDays, m, k);
    cout<<ans<<endl;
    return 0;
}