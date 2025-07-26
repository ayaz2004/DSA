#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int unique_element(vector<int>& nums){
     int ans=0;
     for(auto it:nums) ans=ans^it;
     return ans;
   }
};

int main(){
    vector<int> nums{4, 1, 2, 1, 2};
    Solution sol;
    int ans=sol.unique_element(nums);
    cout<<"Unique element is : ";
    cout<<ans;
    return 0;
}