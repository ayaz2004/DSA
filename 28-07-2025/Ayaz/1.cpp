/*
Your task is to count for k=1,2,…,n the number of ways two knights can be placed on a k*k 
chessboard so that they do not attack each other. 
*/

#include <bits/stdc++.h>
using namespace std;

long long solve(int i){
    long long total_ways=(long long)(((i*i)*((i*i)-1))/2);
    long long not_possible=(long long)(4*(i-1)*(i-2));
    return total_ways-not_possible;
}

int main(){
    int k;
    cout<<"Enter the size of the board : ";
    cin>>k;
    for(int i=1; i<=k; i++) cout<<solve(i)<<endl;
    return 0;
}