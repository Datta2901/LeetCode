#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int> >zeroes;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    zeroes.push({i,j});
                }else{
                    mat[i][j] = -1;
                    // instead of using a visited 2d array
                }
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1,-1, 0 , 0};
        int length - 0;
        while(!zeroes.empty()){
            int size = zeroes.size();
            length++;
            while(size--){
                int x = zeroes.front().first;
                int y = zeroes.front().second;
                zeroes.pop();
                for(int i = 0; i < 4; i++){
                    int nx  = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= m || ny > n || mat[nx][ny] != -1){
                        continue;
                    }
                    mat[nx][ny] = length;
                    zeroes.push({nx,ny});
                }
            }
        }
        return mat;
    }
};

int main(){
    return 0;
}