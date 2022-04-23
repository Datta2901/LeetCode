class Solution {
public:
    int m,n;
    void bfs(vector<vector<char> >& grid,int i, int j){
        queue<pair<int,int>> store;
        store.push({i,j});
        grid[i][j] = '2';
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(!store.empty()){
            int x = store.front().first;
            int y = store.front().second;
            store.pop();
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX < 0 || newY < 0 || newX >= m || newY >= n || grid[newX][newY] != '1'){
                    continue;
                }
                store.push({newX,newY});
                grid[newX][newY] = '2';
            }
        }
    }

    int numIslands(vector<vector<char> >& grid) {
        int islands = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] != '1'){
                    bfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};