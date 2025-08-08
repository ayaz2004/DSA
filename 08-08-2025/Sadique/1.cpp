/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.empty()) return "";
        string ans=strs[0];
        for(string it:strs){
            while(it.find(ans)!=0) ans=ans.substr(0, ans.size()-1);
        }
        return ans;
    }
};

int main(){
    vector<string> strs={"flower", "flow", "flight"};

    Solution sol;
    
    string ans=sol.longestCommonPrefix(strs);

    cout<<ans<<endl;

    return 0;

}