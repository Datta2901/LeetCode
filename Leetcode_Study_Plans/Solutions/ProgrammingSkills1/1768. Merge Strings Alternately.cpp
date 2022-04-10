class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        bool turn = false;
        string answer = "";
        int i = 0,j = 0;
        while(1){
            if(!turn && i < m){
                answer += word1[i];
                i++;
                turn = true;
            }else if(turn &&  j < n){
                answer += word2[j];
                j++;
                turn = false;
            }
            if(i == m && j == n){
                break;
            }if(i == m){
                turn = true;
            }else if(j == n){
                turn = false;
            }
        }
        return answer;
    }
};


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        string answer = "";
        int i = 0,j = 0;
        while(i < m || j < n){
            if(i < m){
                answer += word1[i];
                i++;
            }if(j < n){
                answer += word2[j];
                j++;
            }
        }
        return answer;
    }
};