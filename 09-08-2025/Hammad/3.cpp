/*
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
   int solve(vector<int>& weights, int m){
      int n=weights.size();
      int cnt=1, sum=0;
      for(int i=0; i<n; i++){
        if(sum+weights[i]>m){
            cnt++;
            sum=0;
        }
        sum+=weights[i];
      }
      return cnt;
   }
public:
   int shipWithinDays(vector<int> weights, int days){
     int l=*max_element(weights.begin(), weights.end());
     int h=accumulate(weights.begin(), weights.end(), 0);
     while(l<=h){
        int m=l+(h-l)/2;
        if(solve(weights, m)<=days) h=m-1;
        else l=m+1;
     }
     return l;
   }
};

int main(){
    vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days=5;
    Solution sol;
    int ans=sol.shipWithinDays(weights, days);
    cout<<ans<<endl;
    return 0;
}