class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int ans = (s + s).substr(1,n * 2 - 2).find(s);
        return ans != -1;
    }
};

