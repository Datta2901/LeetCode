#include<bits/stdc++.h>

using namespace std;

int distributeCandies(vector<int>& candyType) {
    set<int>temp;
    for(int i = 0; i < candyType.size(); i++){
        temp.insert(candyType[i]);
    }
    int size = candyType.size()/2,answer;
    if(size >= temp.size()){
        answer = temp.size();
    }else{
        answer = size;
    }
    return answer;
}

int main(){
    int size;
    cin >> size;
    vector<int> candies;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        candies.push_back(a);
    }
    cout << distributeCandies(candies);
}