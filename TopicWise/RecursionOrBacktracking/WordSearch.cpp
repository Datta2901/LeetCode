#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m,n;
    bool backTracking(vector<vector<char> >&board,string word,int index,int x,int y){
        if(index == word.size()){
            return true;
        }
        if(x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '.'){
            return false;
        }
        if(board[x][y] != word[index]){
            return false;
        }
        char a = board[x][y];
        board[x][y] = '.';
        if(backTracking(board,word,index + 1,x + 1,y) || backTracking(board,word,index + 1,x - 1 ,y) || backTracking(board,word,index + 1,x,y + 1) || backTracking(board,word,index + 1,x,y - 1)){
            return true;
        }
        board[x][y] = a;  
        return false; 
    }
    bool exist(vector<vector<char> >& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(backTracking(board,word,0,i,j)){
                    return true;
                }
            }
        }
        return false;
    }
};


int main(){
    Solution obj;
    int n,m;
    cin >> m >> n;
    vector<vector<char> > board(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            char a;
            cin >> a;
            board[i].push_back(a);
        }
    }
    string word;
    cin >> word;
    cout << obj.exist(board,word);
    
    return 0;
}