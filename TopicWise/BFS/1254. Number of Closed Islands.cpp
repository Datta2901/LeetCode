class Solution {
private:
    int count;
     int m;
     int n;
    void bfs(vector<vector<int> >&grid,int X,int Y){
        queue<pair<int,int> > store;
        store.push({X,Y});
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!store.empty()){
            X = store.front().first;
            Y = store.front().second;
            store.pop();
            for(int i = 0; i < 4; i++){
                int x = X + dx[i];
                int y = Y + dy[i];
                if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 0){
                    continue;
                }
                grid[x][y] = 2;
                store.push({x,y});
            }
        }  
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        count = 0;
        m = grid.size();
        n = grid[0].size();
        int corners = 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 0){
                    bfs(grid,i,j);
                }
            }
        }
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(grid[i][j] == 0){
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};