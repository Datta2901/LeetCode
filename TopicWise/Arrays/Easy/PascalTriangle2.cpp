#include<bits/stdc++.h>
using namespace std;


// Formula to find a rc cell in pascal triangle is
//  r - 1 C
//          c - 1
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //By Using Combinations
        vector<int>answer;
        long long int nCr = 1;
        answer.push_back(nCr);
        rowIndex += 1;// 1 based
        for(int i = 1; i < rowIndex; i++){
            nCr = nCr * (rowIndex - i);
            nCr = nCr / i;
            answer.push_back(nCr);
        }
        return answer;
    }
};

int main(){
    Solution obj;
    int size;
    cin >> size;
    vector<int> answer = obj.getRow(size);
    for(auto i : answer){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}