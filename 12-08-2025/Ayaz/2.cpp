/*
A border of a string is a prefix that is also a suffix of the string but not the whole string. For example, the borders of abcababcab are ab and abcab.
Your task is to find all border lengths of a given string.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.length();
    vector<int> v(n, 0);
    for(int i=1; i<n; i++){
        int j=v[i-1];
        while(j>0 && s[i]!=s[j]) j=v[j-1];
        if(s[i]==s[j]) j++;
        v[i]=j;
    }
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
    // cout<<endl;
    vector<int> borders;
    int temp=v[n-1];
    while(temp>0){
        borders.push_back(temp);
        temp=v[temp-1];
        // cout<<temp<<endl;
    }
    sort(borders.begin(), borders.end());

    for(int& it:borders) cout<<it<<" ";
    cout<<endl;

    return 0;
}