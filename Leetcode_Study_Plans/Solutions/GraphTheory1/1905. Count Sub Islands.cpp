class Solution {
    int m,n;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    bool bfs(vector<vector<int> >&grid1,vector<vector<int>>&grid2,int i,int j){
       queue<pair<int,int> > store;
       store.push({i,j});
       int dx[4] = {0,0,1,-1};
       int dy[4] = {1,-1,0,0};
       bool answer = true;
       grid2[i][j] = 2;
       while(!store.empty()){
           int x = store.front().first;
           int y = store.front().second;
           if(grid1[x][y] != 1){
               answer = false;
           }
           store.pop();
           for(int i = 0; i < 4; i++){
               int newX = x + dx[i];
               int newY = y + dy[i];
               if(newX < 0 || newX >= m || newY < 0 || newY >= n || grid2[newX][newY] != 1){
                   continue;
               }
               if(grid1[newX][newY] != 1){
                   answer = false;
               }
               store.push({newX,newY});
               grid2[newX][newY] = 2;
           }
       }
       return answer;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        m = grid2.size();
        n = grid2[0].size();
        int answer = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1){
                    if(bfs(grid1,grid2,i,j)){
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
};