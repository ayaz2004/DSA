/*
Given an integer n, return true if it is a power of two. Otherwise, return false.
An integer n is a power of two, if there exists an integer x such that n == 2x.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   bool isPowerOfTwo1(int n){
    if(n==0) return 0;
    while(n%2==0) return n/=2;
    return n==1;
   }

   bool isPowerOfTwo2(int n){
    return (n>0) && ((n&n-1)==0);
   }
};

int main(){
    int n=3;

    Solution sol;

    bool ans1=sol.isPowerOfTwo1(n);
    cout<<"Answer useing better approach: ";
    cout<<ans1<<endl;

    bool ans2=sol.isPowerOfTwo2(n);
    cout<<"Answer useing better approach: ";
    cout<<ans2<<endl;

    return 0;
}