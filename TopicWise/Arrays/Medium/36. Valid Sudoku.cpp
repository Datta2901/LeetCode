// Algo
// Taking 3 sets row column subarray
// checking whether the current element is present in this row,column,subarray
// if it is present then this is not a valid sudoku
// ele we will insert this element in the present row,present column,present subarray

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board){
        int m = board.size();
        int n = board[0].size();
        unordered_set<char>row[m],column[n],subArray[m / 3][n / 3];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char a = board[i][j];
                if(a != '.'){
                    if(row[i].count(a) || column[j].count(a) || subArray[i / 3][j / 3].count(a)){
                        return false;
                    }
                    row[i].insert(a);
                    column[j].insert(a);
                    subArray[i / 3][j / 3].insert(a);
                }
            }
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isValidSudoku(vector<vector<char> >& board){
//         int m = board.size();
//         int n = board[0].size();
//         unordered_set<char>row[m],column[n],subArray[m / 3][n / 3];
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 char a = board[i][j];
//                 if(a != '.'){
//                     if(row[i].count(a) || column[j].count(a) || subArray[i / 3][j / 3].count(a)){
//                         return false;
//                     }
//                     row[i].insert(a);
//                     column[j].insert(a);
//                     subArray[i / 3][j / 3].insert(a);
//                 }
//             }
//         }
//         return true;
//     }
// };

// Same idea 
class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board){
        int m = board.size();
        int n = board[0].size();
        vector<vector<int> >row(m,vector<int>(n,0));
        vector<vector<int> >column(m,vector<int>(n,0));
        vector<vector<int> > subArray(m,vector<int>(n,0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char ch = board[i][j];
                if(ch != '.'){
                    int a  = board[i][j] - '0' - 1;
                    int index = i / 3 * 3 + j / 3;
                    if(row[i][a] || column[j][a] || subArray[index][a]){
                        return false;
                    }
                    row[i][a] = 1;
                    column[j][a] = 1;
                    subArray[index][a] = 1;
                }
            }
        }
        return true;
    }
};