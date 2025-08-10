/*
The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.
Note: We can either take the item as a whole or break it into smaller units.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   int solve(int n, vector<int>& values, vector<int>& weights, int w){
    vector<pair<double, int>> items;
    for(int i=0; i<n; i++){
        double ratio=(double)values[i]/weights[i];
        items.push_back({ratio, i});
    }
    sort(items.rbegin(), items.rend());
    double sum_weight=0, sum_values=0;
    for(int i=0; i<n; i++){
        int idx=items[i].second;
        if(sum_weight+weights[idx]<=w){
            sum_weight+=weights[idx];
            sum_values+=values[idx];
        }else{
            double remain=w-sum_weight;
            sum_values+=values[idx]*(remain/weights[idx]);
            break;
        }
    }
    return sum_values;
   }
    
};

int main(){
   int n;
   cout<<"Enter the number of items: ";
   cin>>n;

   int w;
   cout<<"Enter the total accepted weight: ";
   cin>>w;

   vector<int> values(n), weights(n);

   cout<<"Enter the weights of each items: "<<endl;
   for(int i=0; i<n; i++) cin>>weights[i];
   
   cout<<"Enter the value of each weights: "<<endl;
   for(int i=0; i<n; i++) cin>>values[i];
   
   Solution sol;

   int ans1=sol.solve(n, values, weights, w);
   cout<<"Answer by brute force appprach is: "<<ans1<<endl;


}