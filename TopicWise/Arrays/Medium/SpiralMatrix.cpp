#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > answer(n, vector<int>(n));
        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = n - 1;
        int count = 1;
    
        while(rowStart <= rowEnd && colStart <= colEnd){
            for(int i = colStart; i<= colEnd; i++)
                answer[rowStart][i] = count++;
            rowStart++;
        
            for(int i = rowStart; i<= rowEnd; i++)
                answer[i][colEnd] = count++;
            colEnd--;
        
            for(int i = colEnd; i>= colStart; i--)
                answer[rowEnd][i] = count++;
            rowEnd--;
        
            for(int i = rowEnd; i>= rowStart; i--)
                answer[i][colStart] = count++;
            colStart++;
        }
        return answer;
    }
};


int main(){
    Solution obj;
    vector<int>num;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        num.push_back(a);
    }
    return 0;
}