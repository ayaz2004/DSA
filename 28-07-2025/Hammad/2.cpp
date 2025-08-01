/*
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
You are given a string word, which represents the final output displayed on Alice's screen.
Return the total number of possible original strings that Alice might have intended to type.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int possibleStringCount(string word){
    int ans=1;
    for(int i=1; i<word.size(); i++) if(word[i-1]==word[i]) ans++;
    return ans;
   }
};
int main(){
    string word="abbcccc";
    Solution sol;
    int ans=sol.possibleStringCount(word);
    cout<<ans<<endl;
    return 0;
}