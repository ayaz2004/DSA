    /*Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.
    In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.
    Return an array containing the index of the row, and the number of ones in it.
    */

    #include <bits/stdc++.h>
    using namespace std;

    vector<int> solve(vector<vector<int>>& mat){
        vector<int> ans;
        int req_row=0, ones_cnt=0;
        for(int i=0; i<mat.size(); i++){
            int cnt=0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1) cnt++;
            }
            if(cnt>ones_cnt){
                req_row=i;
                ones_cnt=cnt;
            }
        }
        ans.push_back(req_row);
        ans.push_back(ones_cnt);
        return ans;
    }

    int main(){
        int m, n;
        cout<<"Enter the number of rows: ";
        cin>>m;
        cout<<"Enter the number of columns: ";
        cin>>n;
        vector<vector<int>> mat(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin>>mat[i][j];
            }
            cout<<endl;
        }

        vector<int> ans=solve(mat);

        for(int it:ans) cout<<it<<" ";
        cout<<endl;
        return 0;
    }