#include <bits/stdc++.h>
using namespace std;

int trie[5000005][26];
bool isEnd[5000005];
int cnt=0;
const int mod=1e9+7;
int dp[5000005];

string s;

void insert_trie(string s){
    int curr=0;
    for(auto& it:s){
        if(!trie[curr][it-'a']){
            trie[curr][it-'a']=++cnt;
        }
        curr=trie[curr][it-'a'];
    }
    isEnd[curr]=1;
}

long long solve(int idx){
    int n=(int)s.length();
    if(idx==n) return dp[n]=1;
    int node=0, ans=0;
    for(int i=idx; i<n; i++){
        if(!trie[node][s[i]-'a']) return dp[idx]=ans;
        node=trie[node][s[i]-'a'];
        if(isEnd[node]){
            if(dp[i+1]!=-1) ans=(ans+dp[i+1])%mod;
            else ans=(ans+solve(i+1))%mod;
        }
    }
    return dp[idx]=ans;
}

int main(){
    int k;
    cin>>s>>k;
    while(k--){
        string str;
        cin>>str;
        insert_trie(str);
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(0)<<endl;
    return 0;
}