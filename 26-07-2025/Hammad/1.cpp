#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   string reverse_word_first(string s){
    reverse(s.begin(), s.end());
    int n=s.length();
    int i=0, l=0, r=0;
    while(i<n){
        while(i<n && s[i]!=' '){
           s[r]=s[i];
           r++;
           i++;
        }
        if(l<r){
            reverse(s.begin()+l, s.begin()+r);
            s[r]=' ';
            r++;
            l=r;
        }
        i++; 
    }
    s=s.substr(0, r-1);
    return s;
   }

   string reverse_word_second(string s){
      stringstream ss(s);
      string token="", ans="";
      while(ss>>token) ans=token+" "+ans;
      return ans.substr(0, ans.length()-1);
   }
};

int main(){
    string s="  hello world  ";
    Solution sol;

    string ans1=sol.reverse_word_first(s);
    cout<<"The answer with first approach will be : ";
    cout<<ans1<<endl;

    string ans2=sol.reverse_word_second(s);
    cout<<"The answer with second approach will be : ";
    cout<<ans2<<endl;

    return 0; 
}