#include<bits/stdc++.h>
using namespace std;


class Solution{
public:
    int solve(vector<int> &A, int B) {
        unordered_map<int,int> fre;
        int XorAnswer = 0;
        int n = A.size();
        int answer = 0;
        for(int i = 0; i < n; i++){
            XorAnswer ^= A[i];
            if(XorAnswer == B){
                answer++;
            }
            cout << i << " " <<  XorAnswer << " " << (XorAnswer ^ B ) << endl;
            fre[XorAnswer]++;
            int subArrayXor = fre[XorAnswer ^ B];
            if(subArrayXor != 0){
                answer += subArrayXor;
            }
        }
        return answer;
    }
};

class Solution1{
public:
    int solve(vector<int> &A, int B) {
        unordered_map<int,int> fre;
        int XorAnswer = 0;
        int n = A.size();
        int answer = 0;
        for(int i = 0; i < n; i++){
            XorAnswer ^= A[i];
            if(XorAnswer == B){
                answer++;
            }
            fre[XorAnswer]++;
            answer += fre[XorAnswer ^ B];
        }
        return answer;
    }
};

int main(){
    int size;
    cin >> size;
    vector<int>nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.solve(nums,k) << endl;
    return 0;
}