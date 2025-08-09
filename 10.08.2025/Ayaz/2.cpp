/*
Given a string and a pattern, your task is to count the number of positions where the pattern 
occurs in the string. 
Input 
The first input line has a string of length n, and the second input line has a pattern of length m. 
Both of them consist of characters a–z. 
Output 
Print one integer: the number of occurrences. 
*/

#include <bits/stdc++.h>
using namespace std;

int solve1(string s1, string s2){
   int n=s1.size(), m=s2.size(), cnt=0;
   for(int i=0; i<=n-m; i++){
    string temp="";
    for(int j=0; j<m; j++){
        temp+=s1[i+j];
    }
    if(temp==s2) cnt++;
   }
    return cnt;
}

vector<int> lps(string s){
    int n=s.size();
    vector<int> v(n, 0);
    int len=0, i=1;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            v[i]=len;
            i++;
        }else{
            if(len!=0) len=v[len-1];
            else{
                v[i]=0;
                i++;
            }
        }
    }
    return v;
}

int solve2(string s1, string s2){
   int n=s1.size(), m=s2.size();
   vector<int> v=lps(s2);
   int i=0, j=0, ans=0;
   while(i<n){
    if(s1[i]==s2[j]){
        i++;
        j++;
    }
    if(j==m){
        ans++;
        j=v[j-1];
    }else if(i<n && s1[i]!=s2[j]){
        if(j!=0) j=v[j-1];
        else i++;
    }
   }
   return ans;
}

int main(){
    string n, m;
    cin>>n;
    cin>>m;

    int ans1=solve1(n, m);
    cout<<"The solution from brute force approch is: ";
    cout<<ans1<<endl;

    int ans2=solve2(n, m);
    cout<<"The solution from optimal approach is: ";
    cout<<ans2<<endl;

    return 0;
}