/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   vector<vector<int>> merge(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for(int i=0; i<intervals.size(); i++){
        if(ans.empty() || intervals[i][0]>ans.back()[1]) ans.push_back(intervals[i]);
        else ans.back()[1]=max(ans.back()[1], intervals[i][1]);
    }
    return ans;
   }
};

int main(){
   vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
   Solution sol;

   vector<vector<int>> ans=sol.merge(intervals);

   for(int i=0; i<ans.size(); i++){
    for(int j=0; j<ans[0].size(); j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
   }
   return 0;
}