#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int x;
    int y;
    int time;
    node(int xx,int yy,int t){
        x = xx;
        y = yy;
        time = t;
    }
};

// int minTimeToRot(vector<vector<int>>& grid, int n, int m)
// {
//     int fresh = 0;
//     queue<node> store;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             if(grid[i][j] == 2){
//                 store.push(node(i,j,0));
//             }if(grid[i][j] != 0){
//                 fresh++;
//             }
//         }
//     }
//     int dx[4] = {1,-1,0,0};
//     int dy[4] = {0,0,1,-1};
//     int maxTime = 0;
//     int count = 0;
//     while(!store.empty()){
//         int x = store.front().x;
//         int y = store.front().y;
//         int t = store.front().time;
//         maxTime = max(maxTime,t);
//         store.pop();
//         count++;
//         for(int i = 0; i < 4; i++){
//             int X = x + dx[i];
//             int Y = y + dy[i];
//             if(X < 0 || X >= n || Y < 0 || Y >= m || grid[X][Y] != 1){
//                 continue;
//             }
//             store.push(node(X,Y,t + 1));
//             grid[X][Y] = 2;
//         }
//     }
//     if(count != fresh){
//         return -1;
//     }
//     return maxTime;
//     // Write your code here. 
// }


int minTimeToRot(vector<vector<int>>& grid, int m, int n)
{
    int TotalOranges = 0;
    queue<node>store;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2){
                store.push(node(i,j,0));
            }if(grid[i][j] != 0){
                TotalOranges++;
            }
        }
    }
    int maxTime = 0;
    int count = 0;  
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    while(!store.empty()){
        int x = store.front().x;
        int y = store.front().y;
        int t = store.front().time;
        maxTime = max(maxTime,t);
        store.pop();
        count++;
        for(int i = 0; i < 4; i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(X < 0 || X >= m || Y < 0 || Y >= n || grid[X][Y] != 1){
                continue;
            }
            store.push(node(X,Y,(t + 1)));
            grid[X][Y] = 2;
        }
    }
    if(count != TotalOranges){
        return -1;
    }
    return maxTime;
}