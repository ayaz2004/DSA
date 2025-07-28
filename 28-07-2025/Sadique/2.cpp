/*
You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
Return the minimum number of different frogs to finish all the croaks in the given string.
A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
  int minNumberOfFrogs(string croakOfFrogs){
    unordered_map<char, int> um;
    string croak="croak";
    int frogs=0, max_frogs=0;
    for(char ch:croakOfFrogs){
        um[ch]++;
        if(ch=='r' && um['r']>um['c']) return -1;
        if(ch=='o' && um['o']>um['r']) return -1;
        if(ch=='a' && um['a']>um['o']) return -1;
        if(ch=='k' && um['k']>um['a']) return -1;
        if(ch=='c'){
            frogs++;
            max_frogs=max(max_frogs, frogs);
        }else if(ch=='k'){
            for(char it:croak) um[it]--;
            frogs--;
        }
    }
    for(char ch:croak){
        if(um[ch]!=0) return -1;
    }
    return max_frogs;
  }
};

int main(){
    string s="crcoakroak";
    Solution sol;
    cout<<sol.minNumberOfFrogs(s)<<endl;
    return 0;
}
