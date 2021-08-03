#include<bits/stdc++.h>
using namespace std;

bool makeEqual(vector<string>& words) {
    map<char,int> freq;
    for(int i = 0; i < words.size(); i++){
        for(int j = 0; j < words[i].size(); j++){
            freq[words[i][j]]++;
        }
    }

    for(auto it : freq){
        if((it.second) % words.size() != 0){
            return false;
        }
    }

    return true;
}

int main(){
    int size;
    cin >> size;
    vector<string> words;
    for(int i = 0; i < size; i++){
        string a;
        cin >> a;
        words.push_back(a);
    }

    cout << makeEqual(words) << endl;
    return 0;
}