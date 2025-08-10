/*
In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
   bool solve(string& a, string& b, unordered_map<char, int>& um){
    int n=min(a.size(), b.size());
    for(int i=0; i<n; i++){
        if(um[a[i]]<um[b[i]]) return true;
        if(um[a[i]]>um[b[i]]) return false;
    }
    return a.size()<=b.size();
   }
public:
   bool isAlienSorted(vector<string>& words, string order){
     unordered_map<char, int> um;
     for(int i=0; i<order.size(); i++) um[order[i]]=i;
     for(int i=0; i<words.size()-1; i++){
        if(!solve(words[i], words[i+1], um)) return false;
     }
     return true;
   }
};

int main(){
   vector<string> words1{"word", "world", "row"};
   string order1="worldabcefghijkmnpqstuvxyz";

   vector<string> words2{"hello", "leetcode"};
   string order2="hlabcdefgijkmnopqrstuvwxyz";

   Solution sol;
   
   bool ans1=sol.isAlienSorted(words1, order1);
   cout<<ans1<<endl;

   bool ans2=sol.isAlienSorted(words2, order2);
   cout<<ans2<<endl;

   return 0;
}