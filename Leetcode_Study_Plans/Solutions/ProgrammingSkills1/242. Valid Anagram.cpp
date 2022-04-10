class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m){
            return false;
        }
        vector<int>mag(26,0);
        for(int i = 0; i < n; i++){
            mag[s[i] - 'a'] += 1;
        }
        for(int i = 0; i < m; i++){
            if(mag[t[i] - 'a'] > 0){
                mag[t[i] - 'a'] -= 1;
            }else{
                return false;
            }
        }
        return true;
    }
};

