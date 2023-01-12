class Solution{
public:
    int solve(vector<int> &A, int B) {
        unordered_map<int,int> fre;
        int XorAnswer = 0;
        int n = A.size();
        int answer = 0;
        for(int i = 0; i < n; i++){
            XorAnswer ^= A[i];
            if(XorAnswer == B){
                answer++;
            }
            fre[XorAnswer]++;
            int subArrayXor = fre[XorAnswer ^ B];
            if(subArrayXor != 0){
                answer += subArrayXor;
            }
        }
        return answer;
    }
};

class Solution{
public:
    int solve(vector<int> &A, int B) {
        unordered_map<int,int> fre;
        int XorAnswer = 0;
        int n = A.size();
        int answer = 0;
        for(int i = 0; i < n; i++){
            XorAnswer ^= A[i];
            if(XorAnswer == B){
                answer++;
            }
            fre[XorAnswer]++;
            answer += fre[XorAnswer ^ B];
        }
        return answer;
    }
};
