/*
You are given a string s of length n, consisting of lowercase Latin letters, and an integer k.
You need to check if it is possible to remove exactly k characters from the string s in such a way that the remaining characters can be rearranged to form a palindrome. Note that you can reorder the remaining characters in any way.
A palindrome is a string that reads the same forwards and backwards. For example, the strings "z", "aaa", "aba", "abccba" are palindromes, while the strings "codeforces", "reality", "ab" are not.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        unordered_map<char, int> um;
        for(char& it:s) um[it]++;
        int odd_cnt=0;
        for(auto &it:um){
            if(it.second%2!=0) odd_cnt++;
        }
        if(odd_cnt==0) cout<<"Yes"<<endl;
        else if(k>=odd_cnt-1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}