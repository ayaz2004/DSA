/*
There is a road, which can be represented as a number line. You are located in the point 0 of the number line, and you want to travel from the point 0 to the point x, and back to the point 0.
You travel by car, which spends 1 liter of gasoline per 1 unit of distance travelled. When you start at the point 0, your car is fully fueled (its gas tank contains the maximum possible amount of fuel).
There are n gas stations, located in points a1,a2,…,an. When you arrive at a gas station, you fully refuel your car. Note that you can refuel only at gas stations, and there are no gas stations in points 0 and x.
You have to calculate the minimum possible volume of the gas tank in your car (in liters) that will allow you to travel from the point 0 to the point x and back to the point 0.
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector<int> a(n+1, 0);
        for(int i=1; i<n+1; i++) cin>>a[i];
        int min_fuel=0;
        for(int i=0; i<n+1; i++) min_fuel=max(min_fuel, (a[i]-a[i-1]));
        min_fuel=max(min_fuel, 2*(x-a[n]));
        cout<<min_fuel<<endl;
    }
    return 0;
}