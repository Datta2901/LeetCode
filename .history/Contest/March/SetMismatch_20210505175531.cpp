#include<bits/stdc++.h>

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    vector<int> answer(nums.size(),0);
    for(int i = 0; i < nums.size(); i++){
        answer[nums[i]]++;
    }

    int twice,repeat;
    for(int i = 0; i < answer.size(); i++){
        if(answer[i] == 2){
            twice = i;
        }if(answer[i] == 0){
            repeat = i;
        }
    }
    answer.clear();
    answer.push_back(twice)
}

int main(){
    int size;
    cin >> size;
    vector<int> numbers;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        numbers.push_back(a);
    }

    return 0;
}