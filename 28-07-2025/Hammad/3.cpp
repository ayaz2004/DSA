/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

   int single_number1(vector<int>& nums){
     vector<int> freq(32, 0);
     int ans=0;
     for(int i=0; i<32; i++){
        for(int j=0; j<nums.size(); j++){
            if((nums[j]&(1<<i))!=0) freq[i]++;
        }
        if(freq[i]%3!=0) ans+=1<<i;
     }
     return ans;
   }

   int single_number2(vector<int>& nums){
      int onces=0, twice=0;
      for(int it:nums){
        onces^=it&~twice;
        twice^=it&~onces;
      }
      return onces;
   }
};

int main(){
    vector<int> nums{2, 2, 3, 2};
    Solution sol;

    cout<<"Solutiom using first approach : ";
    int ans1=sol.single_number1(nums);
    cout<<ans1<<endl;

    cout<<"Solution using second approach : ";
    int ans2=sol.single_number2(nums);
    cout<<ans2<<endl;

    return 0;
}