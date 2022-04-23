class Solution {
private:
    int m,n;
    void bfs(vector<vector<int> >&grid,int X,int Y){
        queue<pair<int,int> > store;
        store.push({X,Y});
        grid[X][Y] = 2;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!store.empty()){
            int x = store.front().first;
            int y = store.front().second;
            store.pop();
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] != 0){
                    continue;
                }
                grid[newX][newY] = 2;
                store.push({newX,newY});
            }
        }        
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int answer = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i * j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 0){
                    bfs(grid,i,j);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    bfs(grid,i,j);
                    answer++;
                }
            }
        }
        return answer;
    }
};