/*
Given a string and patterns, check for each pattern if it appears in the string.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<string> v(k);
    for(int i=0; i<k; i++) cin>>v[i];
    for(auto& it:v){
        if(s.find(it)!=string::npos) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}