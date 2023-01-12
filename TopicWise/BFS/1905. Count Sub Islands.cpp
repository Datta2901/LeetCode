// class Solution {
//     int m,n;
//     int dx[4] = {0,0,1,-1};
//     int dy[4] = {1,-1,0,0};
//     bool 
//     bool bfs(vector<vector<int> >&grid1,vector<vector<int>>&grid2,int i,int j){
//         queue<pair<int,int> > store;
//         store.push({i,j});
//         bool answer = true;
//         while(!store.empty()){
//             int X = store.front().first;
//             int Y = store.front().second;
//             if(grid1[X][Y] != 1){
//                 answer = false;
//             }
//             store.pop();
//             for(int i = 0; i < 4; i++){
//                 int newX = X + dx[i];
//                 int newY = Y + dy[i];
//                 if(newX < 0 || newY < 0 || newX >= m || newY >= n || grid2[newX][newY] != 1){
//                     continue;
//                 }
//                 if(grid1[newX][newY] != 1){
//                     answer = false;
//                 }
//                 store.push({newX,newY});
//                 grid2[newX][newY] = 2;
//             }
//         }
//         return answer;
//     }
// public:
//     int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
//         m = grid2.size();
//         n = grid2[0].size();
//         int answer = 0;
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(grid2[i][j] == 1){
//                     if(bfs(grid1,grid2,i,j)){
//                         answer++;
//                     }
//                 }
//             }
//         }
//         return answer;
//     }
// };

class Solution {
    int m,n;
    bool isSub = true; 
    void dfs(vector<vector<int> >&grid1,vector<vector<int>>&grid2,int i,int j){
        if(i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] != 1){
            return;
        }
        grid2[i][j] = 2;
        if(grid1[i][j] == 0){
            isSub = false;
        }
        dfs(grid1,grid2,i + 1,j);
        dfs(grid1,grid2,i,j + 1);
        dfs(grid1,grid2,i - 1,j);
        dfs(grid1,grid2,i, j - 1);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid2.size();
        n = grid2[0].size();
        int answer = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1){
                    dfs(grid1,grid2,i,j);
                    if(isSub){
                        answer++;
                    }
                    isSub = true;
                }
            }
        }
        return answer;
    }
};