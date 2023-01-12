#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n){   
        map<int,int>store;
        int answer = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += A[i];
            if(sum == 0){
                answer = i + 1;
            }else{
                if(store[sum] != 0){
                    answer = max(answer,i + 1 - store[sum]);  
                }else{
                    store[sum] = i + 1; 
                }
            }
        }
        return answer;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}

