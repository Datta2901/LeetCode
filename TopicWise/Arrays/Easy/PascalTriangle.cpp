#include<bits/stdc++.h>
using namespace std;


// Formula to find a rc cell in pascal triangle is
//  r - 1 C
//          c - 1


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal(numRows);
        for(int i = 0; i < numRows; i++){
            pascal[i].resize(i + 1);
            pascal[i][0] = 1;
            pascal[i][i] = 1;
            for(int j = 1; j < i; j++){
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
        return pascal;
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