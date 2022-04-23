class Solution{
    private:
        int maximum = 0;
        int m,n;
    public:
        void bfs(vector<vector<int> >& grid,int i,int j){
            int count = 1;
            queue<pair<int,int> > store;
            store.push({i,j});
            grid[i][j] = 2;
            int dx[4] = {1,-1,0,0};
            int dy[4] = {0,0,-1,1};
            while(!store.empty()){
                int x = store.front().first;
                int y = store.front().second;
                store.pop();
                for(int i = 0; i < 4; i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if(newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 1){
                        continue;
                    }
                    grid[newX][newY] = 2;
                    store.push({newX,newY});
                    count++;
                }
                maximum = max(maximum,count);
            }
        }
        int maxAreaOfIsland(vector<vector<int> >& grid) {
            m = grid.size();
            n = grid[0].size();
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] != 0){
                        bfs(grid,i,j);
                    }
                }
            }
            return maximum;
        }
};
