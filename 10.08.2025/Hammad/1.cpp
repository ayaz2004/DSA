/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int numberOfSubstrings1(string s){
     int n=s.size(), ans=0;
     for(int i=0; i<n; i++){
        int freq[3]={0};
        for(int j=i; j<n; j++){
            freq[s[j]-'a']++;
            if(freq[0]>0 && freq[1]>0 && freq[2]) ans++;
        }
     }
     return ans;
   }

   int numberOfSubstrings2(string s){
      int n=s.length();
      int l=0, r=0, ans=0;
      vector<int> freq(3, 0);
      while(r<n){
        freq[s[r]-'a']++;
        while(freq[0] && freq[1] && freq[2]){
           ans+=n-r;
           freq[s[l]-'a']--;
           l++;
        }
        r++;
      }
      return ans;
   }
};

int main(){
   string s="abcabc";

   Solution sol;

   int ans1=sol.numberOfSubstrings1(s);
   cout<<"Answer by brute-force is: ";
   cout<<ans1<<endl;
   
   int ans2=sol.numberOfSubstrings2(s);
   cout<<"Answer by optimal approach is: ";
   cout<<ans2<<endl;

   return 0;
}