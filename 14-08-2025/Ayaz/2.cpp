/*
Flowey has planted a bomb in Snowdin!
The bomb has a timer that is initially set to b. Every second, the timer will decrease by 1. When the timer reaches 0, the bomb will explode! To give the residents of Snowdin enough time to evacuate, you will need to delay the bomb from exploding for as long as possible.
You have n tools. Each tool can only be used at most once. If you use the i-th tool, the timer will increase by xi. However, if the timer is changed to an integer larger than a, the timer will be set to a due to a bug. More specifically, the following events will happen every second in the following order:
You will choose some (possibly none) of your tools that have not been used before. If you choose the i-th tool, and the bomb's timer is currently set to c, the timer will be changed to min(c+xi,a). The timer decreases by 1.If the timer reaches 0,the bomb explodes.Jellyfish now wants to know the maximum time in seconds until the bomb explodes if the tools are used optimally.
*/

#include <bits/stdc++.h>
using namespace std;

// void brute_force(){
//     int a, b, n;
//     cin>>a>>b>>n;
//     vector<int> x(n);
//     for(int i=0; i<n; i++) cin>>x[i];
//     sort(x.begin(), x.end(), greater<int>());
//     long long cnt=0;
//     int c=b;
//     for(int i=0; i<n; i++){
//         while(c<a && c>1){
//             c--;
//             cnt++;
//         }
//         c=min(c+x[i], a);
//         c--;
//         cnt++;
//         if(c==0) break;
//     }
//     cnt+=c;
//     cout<<cnt<<endl;
// }


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
       int a, b, n;
       cin>>a>>b>>n;
       vector<int> x(n);
       for(int i=0; i<n; i++) cin>>x[i];
       long long cnt=b;
       for(int i=0; i<n; i++){
           cnt+=min(x[i], a-1);
       }
       cout<<cnt<<endl;
       }
    return 0;
}