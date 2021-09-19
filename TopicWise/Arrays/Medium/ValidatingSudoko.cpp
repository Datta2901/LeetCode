#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isCorrect(vector<vector<char> >& board,int row,int col){
        for
    }

    bool isValidSudoku(vector<vector<char> >& board) {
        for(int i = 0; i < 9; i++){
            map<char,int> fre;          
            // validating for rows  
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(fre[board[i][j]] == 0){
                        fre[board[i][j]] += 1;
                    }else{
                        return false;
                    }
                }
            }
            fre.clear();
            // validating for columns
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    if(fre[board[j][i]] == 0){
                        fre[board[j][i]] += 1;
                    }else{
                        return false;
                    }
                }
            }
        }

        //Validating the subarrays of size 3 * 3;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                
            }
        }

        return true;
    }
};


int main(){
    Solution obj;
    vector<vector<char> >num(9);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            char a;
            cin >> a;
            num[i].push_back(a);
        }
    }
    // for(auto it : num){
    //     for(auto i : it){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    cout << obj.isValidSudoku(num) << endl;
    return 0;
}

bool isValidSudoku(vector<vector<char> >& board){
        set<char> row[9];
        set<char> col[9];
        set<char> sub[3][3];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
               char a = board[i][j];
                if(a != '.'){                     
                    if(row[i].count(a) || col[j].count(a) || sub[i/3][j/3].count(a))
                        return false;
                }
				col[j].insert(a);
				row[i].insert(a);
				sub[i / 3][j / 3].insert(a);
            }
        }
	 return true;
}