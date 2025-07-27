/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   long long solve(string s){
    long long ans=0;
    int sign=1;
    stack<pair<int, int>> st;
    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9'){
            long long temp=0;
            while(i<s.size() && s[i]>='0' && s[i]<='9'){
                temp=temp*10+(s[i]-'0');
                i++;
            }
            ans+=temp*sign;
            sign=1;
            i--;
        }else if(s[i]=='('){
            st.push({ans, sign});
            ans=0;
            sign=1;
        }else if(s[i]==')'){
            int prev_sum=st.top().first, prev_sign=st.top().second;
            st.pop();
            ans=prev_sum+prev_sign*ans;
        }else if(s[i]=='-') sign=-1;
    } 
    return ans; 
   }
};

int main(){
   string s="(1+(4+5+2)-3)+(6+8)";
   Solution sol;
   long long ans=sol.solve(s);
   cout<<ans<<endl;
   return 0;
}