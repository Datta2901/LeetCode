#include<bits/stdc++.h>

using namespace std;

int distributeCandies(vector<int>& candyType) {
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        candies.push_back(a);
        temp.insert(a);
    }
}

int main(){
    int size;
    cin >> size;
    vector<int> candies;
    set<int>temp;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        candies.push_back(a);
        temp.insert(a);
    }
    size /= 2;
    
}