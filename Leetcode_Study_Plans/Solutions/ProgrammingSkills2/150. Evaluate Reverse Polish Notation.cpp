#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>store;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i].size() > 1)){
                int num = 0;        
                bool neg = false;
                for(auto it : tokens[i]){
                    if(it == '-'){
                        neg = true;
                    }else{
                        num = (10*num) +  (it -'0');
                    }
                }
                if(neg){
                    num *= -1;
                }
                cerr << num << " ";
                store.push(num);
            }else{
                int f = store.top();
                store.pop();
                int s = 0;
                if(!store.empty()){
                    s = store.top();
                    store.pop();
                }
                if(tokens[i][0] == '+'){
                    store.push(s + f);
                }
                if(tokens[i][0] == '*'){
                    store.push(s * f);
                }
                if(tokens[i][0] == '/'){
                    store.push(s / f);
                }
                if(tokens[i][0] == '-'){
                    store.push(s - f);
                }
            }
        }
        if(!store.empty())
        return store.top();
        return 0;
    }
};

int main(){
    Solution obj;
    int n;
    cin >> n;
    vector<string>nums;
    for(int i = 0; i < n; i++){
        string a;
        cin >> a;
        nums.push_back(a);
    }
    cout << obj.evalRPN(nums) << endl;
    return 0;
}