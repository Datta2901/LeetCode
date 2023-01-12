#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> repeatedNumber(vector<int> &A);
};


vector<int> Solution ::repeatedNumber(vector<int> &A) {
    vector<int>ans;
    int num1 = 0,num2 = 0,result = 0;
    int n = A.size();
    for(int i = 0; i < n; i++){
        result ^= A[i];
    }
    for(int i = 1; i <= n; i++){
        result ^= i;
    }
    int rightMostSetBit = result & (~(result - 1));
    for(int i = 0; i < n; i++){
        if(rightMostSetBit & A[i]){
            cout << A[i] << " ";
            num1 ^= A[i];
        }else{
            cout << -A[i] << " ";
            num2 ^= A[i];
        }
    }
    cout << endl;

    for(int i = 1; i <= n; i++){
        if(rightMostSetBit & i){
            cout << i << " ";
            num1 ^= i;
        }else{
            cout << -i << " ";
            num2 ^= i;
        }
    }
    cout << endl;
    bool control = false;
    for(int i = 0; i < n; i++){
        if(num1 == A[i]){
            control = true;
            return {num1,num2};
        }
    }
    if(!control){
        return {num2,num1};
    } 
}

int main(){
    Solution obj;
    int size;
    cin >> size;
    vector<int>answer;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        answer.push_back(a);
    }
    answer = obj.repeatedNumber(answer);
    for(auto it : answer){
        cout << it << " ";
    }
    return 0;
}