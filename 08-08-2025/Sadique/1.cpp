/*
You are given a string word, and an integer numFriends.
Alice is organizing a game for her numFriends friends. There are multiple rounds in the game, where in each round:
word is split into numFriends non-empty strings, such that no previous round has had the exact same split.
All the split words are put into a box.
Find the lexicographically largest string from the box after all the rounds are finished.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    string answerString(string word, int numFriends){
       if(numFriends==1) return word;
       int n=word.size();
       string ans;
       for(int i=0; i<n; i++){
          ans=max(ans, word.substr(i, min(n-numFriends+1, n-i)));
       }
       return ans;
    }

};

int main(){
    string word="dbca";
    int numFriends=2;
    Solution sol;
    string ans=sol.answerString(word, numFriends);
    cout<<ans<<endl;
    return 0;
}