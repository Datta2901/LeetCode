// class Solution {
//     void dfs(vector<vector<int> >&grid,int i,int j){
//         if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0){
//             return;
//         }
//         grid[i][j] = 0;
//         dfs(grid,i + 1,j);
//         dfs(grid,i,j + 1);
//         dfs(grid,i - 1,j);
//         dfs(grid,i,j - 1);
//     }
// public:
//     int numEnclaves(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
        
//         for(int  i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid[i][j] == 1){
//                     if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
//                         dfs(grid,i,j);
//                     }
//                 }
//             }
//         }
//         int answer = 0;
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid[i][j] == 1){
//                     answer++;
//                 }
//             }
//         }
//         return answer;
//     }
// };


class Solution {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    void bfs(vector<vector<int> >&grid,int i,int j){
        queue<pair<int,int> > store;
        store.push({i,j});
        grid[i][j] = 0;
        while(!store.empty()){
            int X = store.front().first;
            int Y = store.front().second;
            store.pop();
            for(int i = 0; i < 4; i++){
                int newX = X + dx[i];
                int newY = Y + dy[i];
                if(newX < 0 || newX >= grid.size() || newY < 0 || newY >= grid[0].size() || grid[newX][newY] == 0){
                    continue;
                }
                grid[newX][newY] = 0;
                store.push({newX,newY});
            }
            
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int  i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    if(i == 0 || i == m - 1 || j == 0 || j == n - 1){
                        bfs(grid,i,j);
                    }
                }
            }
        }
        int answer = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    answer++;
                }
            }
        }
        return answer;
    }
};