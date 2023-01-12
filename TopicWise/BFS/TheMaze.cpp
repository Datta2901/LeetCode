#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool CanWeReach(vector<int>&start,vector<int>&destination,vector<vector<int> > &grid){
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<bool> > visited(m,vector<bool>(n,false));
            int dx[4] = {1,-1,0,0};
            int dy[4] = {0,0,1,-1};  
            queue<pair<int,int> > track;
            track.push({start[0],start[1]});
            visited[start[0]][start[1]] = true;
            while(!track.empty()){
                int x = track.front().first;
                int y = track.front().second;
                track.pop();
                if(x == destination[0] && y == destination[1]){
                    return true;
                }
                for(int i = 0; i < 4; i++){
                    int newX = x;
                    int newY = y;
                    while(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 0){
                        newX += dx[i];
                        newY += dy[i];
                    }
                    newX -= dx[i];
                    newY -= dy[i];
                    if(!visited[newX][newY]){
                        visited[newX][newY] = true;
                        track.push({newX,newY});
                    }
                }
            }
            return false;
        }
}

int main(){

    return 0;
}