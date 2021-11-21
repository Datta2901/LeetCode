#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
        bool isVowel(char a){
            if(a == 'a' || a == 'e' ||a == 'i' ||a == 'o' ||a == 'u'){
                return true;
            }
            return false;
        }

        int GetAnswer(string s,int k){
            unordered_map<char,int>fre;
            int answer = 0;
            int i = 0;
            for(int j = 0; j < s.size(); j++){
                if(!isVowel(s[j])){
                    i = j + 1;
                    fre.clear();
                    continue;
                }
                fre[s[j]]++;
                while(fre.size() > k){
                    fre[s[i]] -= 1;
                    if(fre[s[i]] == 0){
                        fre.erase(s[i]);
                    }
                    i++;
                }
                answer += (j - i + 1); 
            }
            return answer;
        }
    public:
        // Brute Force
        // int countVowelSubstrings(string word) {
        //     int n = word.size();
        //     int answer = 0;
        //     for(int i = 0; i < n; i++){
        //         set<int>store;
        //         for(int j = i; j < n; j++){
        //             if(isVowel(word[j])){
        //                 store.insert(word[j]);
        //                 if(store.size() == 5){
        //                     answer++;
        //                 }
        //             }else{
        //                 break;
        //             }
        //         }
        //     }
        //     return answer;
        // }

        // count vowel substrings having  k vowels
        int countVowelSubstrings(string word) {
            return GetAnswer(word,5) - GetAnswer(word,4);
        }

};

int main(){
    Solution obj;
    string s;
    cin >> s;
    cout << obj.countVowelSubstrings(s) << endl;

    return 0;
}