class Solution {
private:
    vector<vector<string> > answer;
    int n;
    bool isPalindrome(string s){
        string rev = s;
        reverse(s.begin(),s.end());
        return rev == s;
    }

public:
    void recursive(string &s,int start,vector<string>&currentList){
        if(start >= n){
            answer.push_back(currentList);
        }
        for(int end = start; end < n; end++){
            string a = s.substr(start,end - start + 1);
            if(isPalindrome(a)){
                currentList.push_back(a);
                recursive(s,end + 1,currentList);
                currentList.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<string>current;
        int start = 0;
        recursive(s,0,current);
        return answer;
    }
};