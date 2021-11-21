#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
int track(vector<vector<int> >& grid,int i,int j,int zeroes) {
    if(i < 0||j < 0||i >= grid.size()||j >= grid[0].size()||grid[i][j] == -1){
         return 0;
    }

    if(grid[i][j] == 2) {
        return (zeroes == -1)?1:0;
    }
    grid[i][j] = -1;
    zeroes--;
    int answer = track(grid,i+1,j,zeroes)+track(grid,i,j+1,zeroes)+track(grid,i-1,j,zeroes)+track(grid,i,j-1,zeroes);
    grid[i][j] = 0;
    zeroes++;
    return answer;
}
int uniquePathsIII(vector<vector<int> >& grid) {
    int row = grid.size();
    int col = grid[0].size();
    
    int startx,starty,total=0;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(grid[i][j] == 1) {
                startx = i; starty = j;
            }
            if(grid[i][j] == 0){
                 ++total;
            }
        }
    }
    
    return track(grid,startx,starty,total);
}
};