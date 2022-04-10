class Solution {
public:
    string freqAlphabets(string s) {
        int num  = 0;
        string answer = "";
        bool belongs = false;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '#'){
                char a = 'a' + num - 1;
                answer += a;
                num = 0;
                belongs = false;
            }else if((i + 2 < n && s[i + 2] == '#') || belongs){
                num = num * 10 + s[i] - '0';
                belongs = true;
            }else{
                answer += ('a' + (s[i] - '0') - 1);
            }
        }
        return answer;
    }
};