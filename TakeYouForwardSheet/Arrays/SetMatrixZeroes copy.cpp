#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // tc - O(n2)
    // sc - O(n)
    // Approach : store row ( as +ve) and column as (-ve)
    // if row or column as 0 make it true and update 0 at that position
    void setZeroes(vector<vector<int>>& matrix) {
        map<int,bool> cells;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    cells[i + 1] = true;
                    cells[-1 * (j + 1)] = true;
                    cout << i + 1 << " " << -1 * (j + 1) << endl;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(cells[i + 1] || cells[-1 * (j + 1)]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
public:
    // tc - O(n2)
    // sc - O(1)
    // Approach : if we find zero then make first row of that row and column as zero
    void setZeros(vector<vector<int>> &matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        bool col = true;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                col = false;
            }
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j > 0; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
                if(col == false){
                    matrix[i][0] = 0;
                }
            }
    }
};


int main(){
    int m,n;
    cin >> m >> n;
    vector<vector<int> > matrix(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            matrix[i].push_back(a);
        }
    } 
    
    return 0;
}

