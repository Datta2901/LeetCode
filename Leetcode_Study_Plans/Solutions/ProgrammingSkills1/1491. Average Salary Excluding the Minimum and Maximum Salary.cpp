#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        int mini = *min_element(salary.begin(),salary.end());
        int maxi = *max_element(salary.begin(),salary.end());
        int sum = accumulate(salary.begin(),salary.end(),0);
        int n = salary.size() - 2;
        sum = sum - maxi - mini;
        double mean = double(sum) / n;
        return mean;
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
    cout << obj.average(num) << endl;
    return 0;
}