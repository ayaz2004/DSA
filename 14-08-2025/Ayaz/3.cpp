/*
You are given a string of length n and a dictionary containing k words. In how many ways can you create the string using the words?
*/

#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

vector<long long> dp;

long long waysFrom(int i, string &s, vector<string> &k){
    int n=(int)s.length();
    // dp.resize(n+1, -1);
    if(i==n) return 1;
    if(dp[i]!=-1) return dp[i];
    long long ans=0;
    for(auto& it:k){
        if(i+(int)it.size()<=n && s.compare(i, it.size(), it)==0){
            ans=(ans+waysFrom(i+it.size(), s, k))%mod;
        }
    }
    return dp[i]=ans;
}

long long solve_brute_force(vector<string> &k, string &s){
    dp.assign(s.size()+1, -1);
    return waysFrom(0, s, k);
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<string> arr(k);
    for(int i=0; i<k; i++) cin>>arr[i];

    // cout<<"Answer form brute force approach is: ";
    long long ans1=solve_brute_force(arr, s);
    cout<<ans1<<endl;
    
}