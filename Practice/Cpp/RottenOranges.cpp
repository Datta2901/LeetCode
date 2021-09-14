#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int> >rotten;
        int count = 0,total = 0,days = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    total += 1;
                }
                if(grid[i][j] == 2){
                    rotten.push({i,j}); 
                }
            }
        }
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        while(!rotten.empty()){
            int k = rotten.size();
            count += k;
            while(k--){
                int x = rotten.front().first,y = rotten.front().second;
                rotten.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >=m || grid[nx][ny] != 1){
                        continue;
                    }
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                }
            }
            if(!rotten.empty()){
                days += 1;
            }
        }
        if(total == count){
            return days;
        }
        return -1;
    }
};


int main(){
    return 0;
}