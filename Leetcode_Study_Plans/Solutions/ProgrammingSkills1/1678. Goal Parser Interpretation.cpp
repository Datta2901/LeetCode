class Solution {
public:
    string interpret(string command) {
        int open = -1;
        string answer = "";
        int n = command.size();
        for(int i = 0; i < n; i++){
            if(command[i] == '('){
                open = i;
            }else if(command[i] == ')'){
                if(i - open == 1){
                    answer += "o";
                }else{
                    answer += "al";
                }
            }else if(command[i] == 'G'){
                answer += "G";
            }
        }
        return answer;
    }
};