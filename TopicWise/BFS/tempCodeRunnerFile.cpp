lass Solution {
// public:
//     int m,n;
//     int dx[4] = {1,-1,0,0};
//     int dy[4] = {0,0,-1,1};
//     void bfs(vector<vector<char> >&board,int i,int j){
//         queue<pair<int,int> >store;
//         store.push({i,j});
//         board[i][j] = '_';
//         while(!store.empty()){
//             int X = store.front().first;
//             int Y = store.front().second;
//             store.pop();
//             for(int i = 0; i < 4; i++){
//                 for(int j = 0; j < 4; j++){
//                     int newX = X + dx[i];
//                     int newY = Y + dy[i];
//                     if(newX < 0 || newX >= m || newY < 0 || newY >= n || board[newX][newY] != 'O'){
//                         continue;
//                     }
//                     board[newX][newY] = '_';
//                     store.push({newX,newY});
//                 }
//             }
//         }        
//     }
//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if((i == 0 || j == n - 1 || j == 0 || i == m - 1) && (board[i][j] == 'O')){
//                     bfs(board,i,j);
//                 }
//             }
//         }
       
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(board[i][j] == '_'){
//                     board[i][j] = 'O';
//                 }else{
//                     board[i][j] = 'X';
//                 }
//             }
//         }
//     }
// };