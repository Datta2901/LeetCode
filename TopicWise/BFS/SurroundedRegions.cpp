#include<bits/stdc++.h>
using namespace std;



// Recursive
class Solution {
public:
    void solve(vector<vector<char> >& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = '_';
                }
            }
        }
        //Flood FIll on boundaries
        
        // 1st row
        for(int i = 0; i < n; i++){
            if(board[0][i] == '_'){
                Flood_fill(board,0,i);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][n - 1] == '_'){
                Flood_fill(board,i,n - 1);
            }
        }

        for(int i = 0; i < n; i++){
            if(board[m - 1][i] == '_'){
                Flood_fill(board,m - 1,i);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][0] == '_'){
                Flood_fill(board,i,0);
            }
        }
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
    void Flood_fill(vector<vector<char> >& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        if(i < 0 || j < 0 || i >= m || j >= n){
            return ;
        }if(board[i][j] != '_'){
            return ;
        }
        board[i][j] = 'O';
        Flood_fill(board,i + 1,j);
        Flood_fill(board,i - 1,j);
        Flood_fill(board,i,j + 1);
        Flood_fill(board,i,j - 1);
        return;
    }
};



// Iterative
class Solution2 {
public:
    void solve(vector<vector<char> >& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = '_';
                }
            }
        }
        //Flood FIll on boundaries
        // 1st row
        for(int i = 0; i < n; i++){
            if(board[0][i] == '_'){
                Flood_fill(board,0,i);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][n - 1] == '_'){
                Flood_fill(board,i,n - 1);
            }
        }

        for(int i = 0; i < n; i++){
            if(board[m - 1][i] == '_'){
                Flood_fill(board,m - 1,i);
            }
        }

        for(int i = 0; i < m; i++){
            if(board[i][0] == '_'){
                Flood_fill(board,i,0);
            }
        }
        
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '_'){
                    board[i][j] = 'X';
                }
            }
        }  
    }
    void Flood_fill(vector<vector<char> >& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int> > track;
        track.push({i,j});
        board[i][j] = 'O';
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0, 0,-1,1};
        while(!track.empty()){
            int X = track.front().first;
            int Y = track.front().second;
            track.pop();
            for(int k = 0; k < 4; k++){
                int x = X + dx[k];
                int y = Y + dy[k];
                if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] != '_'){
                    continue;
                }
                board[x][y] = 'O';
                track.push({x,y});
            }
        }
    }
};

// Final
// class Solution {
// public:
//     int m,n;
//     void dfs(vector<vector<char> >&board,int i,int j){
//         if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O' ){
//             return;
//         }
//         board[i][j] = '_';
//         dfs(board,i,j + 1);
//         dfs(board,i + 1,j);
//         dfs(board,i - 1,j);
//         dfs(board,i,j - 1);
//     }
//     void solve(vector<vector<char>>& board) {
//         m = board.size();
//         n = board[0].size();
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if((i == 0 || j == n - 1 || j == 0 || i == m - 1) && (board[i][j] == 'O')){
//                     dfs(board,i,j);
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


// class Solution {
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

int main(){
    Solution2 obj;
    int m,n;
    cin >> m >> n;
    // cerr<< m << " " << n << endl;
    vector<vector<char> >num(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char a;
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