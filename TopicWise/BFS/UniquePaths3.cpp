#include<bits/stdc++.h>
using namespace std;


// Recursive
class Solution {
public:
    int track(vector<vector<int> >& grid,int i,int j,int zeroes) {
        if(i < 0||j < 0||i >= grid.size()||j >= grid[0].size()||grid[i][j] == -1){
            return 0;
        }
        if(grid[i][j] == 2) {
            return (zeroes == -1) ? 1 : 0;
        }
        grid[i][j] = -1;
        zeroes--;
        int answer = track(grid,i+1,j,zeroes) + track(grid,i,j+1,zeroes) + track(grid,i-1,j,zeroes) + track(grid,i,j-1,zeroes);
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


// Iterative
class Solution {
public:
    int track(vector<vector<int> >& grid,int i,int j,int zeroes) {
        queue<pair<int,int> > qp;
        qp.push({i,j});
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        while(!qp.empty()){
            int X = qp.front().first;
            int Y = qp.front().second;
            int size = qp.size();
            while(size--){
                for(int k = 0; k < 4; k++){
                    int x = X + dx[k];
                    int y = Y + dy[k];
                    if(x < 0 || y < 0 || x >= m || j >= n || grid[i][j] == -1){
                        continue;
                    }
                    grid[x][y] = -1;
                    qp.push({x,y});
                }
            }
            if(!qp.empty()){
                zeroes--;
            }
        }

        if(i < 0||j < 0||i >= grid.size()||j >= grid[0].size()||grid[i][j] == -1){
            return 0;
        }
        if(grid[i][j] == 2) {
            return (zeroes == -1) ? 1 : 0;
        }



        grid[i][j] = -1;
        zeroes--;
        int answer = track(grid,i+1,j,zeroes) + track(grid,i,j+1,zeroes) + track(grid,i-1,j,zeroes) + track(grid,i,j-1,zeroes);
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

int main(){
    Solution2 obj;
    int m,n;
    cin >> m >> n;
    vector<vector<int> >num(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            num[i].push_back(a);
        }
    }
    // cout << m << n << num[0][0] << endl;
    

    obj.solve(num);
    for(auto i : num){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}