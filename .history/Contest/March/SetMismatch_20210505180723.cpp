#include<bits/stdc++.h>

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> answer(nums.size() + 1,0);
    for(int i = 0; i < nums.size(); i++){
        answer[nums[i]]++;
    }

    int twice,miss;
    for(int i = 0; i < answer.size(); i++){
        if(answer[i] == 2){
            twice = i;
        }if(answer[i] == 0){
            miss = i;
        }
    }
    answer.clear();
    answer.push_back(twice);
    answer.push_back(miss);
    return answer;
}



/** Assume m is missing and d is duplicate element
 *  
         diff= m-d;
         quareDiff= m^2-d^2;
         sum=m+d= squareDiff/diff
         =>sum    = (m+d)(m-d)/(m-d);
         now m=(sum+diff)2;
         and d= (sum-diff)2;
**/

int main(){
    int size;
    cin >> size;
    vector<int> numbers;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        numbers.push_back(a);
    }
    vector<int> answer = findErrorNums(numbers);
    cout << answer[0] << " " << answer[1] << endl;
    
    return 0;
}