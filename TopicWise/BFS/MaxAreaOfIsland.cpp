#include<bits/stdc++.h>
using namespace std;



class Solution{
    public:
        int dfs(vector<vector<int> >& grid,int i,int j){
            int row = grid.size();
            int col = grid[0].size();
            if((i < 0 || i >= row) || (j < 0 ||j >= col) ||  grid[i][j] == 0 || grid[i][j] == 2){
                return 0;
            }
            grid[i][j] = 2;

            return 1 + dfs(grid,i - 1,j) + dfs(grid,i + 1,j) + dfs(grid,i,j + 1) + dfs(grid,i,j - 1); 
        }

        int maxAreaOfIsland(vector<vector<int> >& grid) {
            int row = grid.size();
            int col = grid[0].size();
            int maxi = INT_MIN;
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(grid[i][j] != 0){
                        maxi = max(maxi,dfs(grid,i,j));
                    }
                }
            }
            return maxi;
        }
};



int main(){
    Solution obj;
    vector<int>num;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    return 0;
}