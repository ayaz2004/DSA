/*
You are given a string word that consists of digits and lowercase English letters.
You will replace every non-digit character with a space. For example, "a123bc34d8ef34" will become " 123  34 8  34". Notice that you are left with some integers that are separated by at least one space: "123", "34", "8", and "34".
Return the number of different integers after performing the replacement operations on word.
Two integers are considered different if their decimal representations without any leading zeros are different.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int calculate_integer(string s){
        int n=s.length(), i=0;
        unordered_set<string> us;
        while(i<n){
            if(s[i]<'0' || s[i]>'9'){
               i++;
               continue;
            }
            string temp="";
            while(i<n && s[i]>='0' && s[i]<='9'){
                temp+=s[i];
                i++;
            }
            int j=0;
            while(j<temp.size() && temp[j]=='0') j++;
            temp+=temp.substr(j);
            us.insert(temp);
        }
        return us.size();
    }
  
};
int main(){
    string s="a1b01c001";
    Solution sol;
    int ans=sol.calculate_integer(s);
    cout<<ans<<endl;
    return 0;
}