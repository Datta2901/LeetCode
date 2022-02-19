// int dx[4] = {0,0,1,-1};
// int dy[4] = {1,-1,0,0};
// int n,m;
// bool isvalid(int nx,int ny)
// {
//     if(nx>=0 && ny>=0 && nx<n && ny<m)
//     return true;
//     return false;
// }
// int solve(vector<vector<int>>& matrix) {
//       n =matrix.size();
//      m = matrix[0].size();
//     queue<pair<int,int>>q;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(matrix[i][j]!=1)
//             {
//                 q.push({i,j});
//             }
//         }
//     }
//     int  lev = 1;
//     int mx = 0;
//     while(!q.empty())
//     {
//         int sz = q.size();
//         while(sz--)
//         {
//             auto k = q.front();
//             q.pop();
//             int x = k.first;
//             int y = k.second;
//             for(int i=0;i<4;i++)
//             {
//                 int nx = x + dx[i];
//                 int ny = y + dy[i]; 
//                 if(isvalid(nx,ny) && matrix[nx][ny]==1)
//                  {
//                      mx = max(mx,lev);
//                      matrix[nx][ny] = 0 ;
//                      q.push({nx,ny});
//                  }                             
//             }           
//         }      
//         lev++;
//     }
//     return mx==0 ? -1 : mx;
// }

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};

    int solve(vector<vector<int> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        queue<pair<int,int> > store;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    store.push({i,j});
                }
            }
        }

        int answer = INT_MIN;
        int count = 0;
        while(!store.empty()){
            int size = store.size();
            while(size--){
                int x = store.front().first;
                int y = store.front().second;
                store.pop();
                for(int i = 0; i < 4; i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    // if(newX < 0 || newY < 0|| newX >= m || newY >= n || matrix[newX][newY] != 1){
                    //     continue;
                    // }
                    if(newY >= 0 && newX >= 0 && newX < m && newY < n && matrix[newX][newY] == 1){
                        answer = max(answer,count);
                        matrix[newX][newY] = 2; 
                        store.push({newX,newY});
                    }
                }
            }
            count++;
        }
        // answer = max(answer,count);
        if(answer == 0){
            return -1;
        }
        return answer;
    }

};

int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int> > matrix(m,vector<int>(n,0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    Solution obj;
    cout << obj.solve(matrix) << endl;
    return 0;
}