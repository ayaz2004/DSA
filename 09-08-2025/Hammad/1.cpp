/*
Geek is a software engineer. He is assigned with the task of calculating average waiting time of all the processes by following shortest job first policy.
The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next.
Given an array of integers bt of size n. Array bt denotes the burst time of each process. Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.
Note: Consider all process are available at time 0.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& bt){
    sort(bt.begin(), bt.end());
    int wt=0, total_wt=0;
    for(int i=0; i<n; i++){
        total_wt+=wt;
        wt+=bt[i];
    }
    return total_wt/n;
}

int main(){
    int n;
    cin>>n;
    vector<int> bt(n);
    for(int i=0; i<n; i++) cin>>bt[i];

    int ans=solve(n, bt);

    cout<<ans;

    return 0;
}