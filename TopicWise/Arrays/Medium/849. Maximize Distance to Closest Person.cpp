class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int zero = 0;
        int n = seats.size();
        int maxi = INT_MIN;
        bool middle = false;
        int answer = 0;
        for(int i = 0; i < n; i++){
            if(seats[i] == 0){
                zero++;
            }else{
                if(maxi == INT_MIN){
                    maxi = zero;
                }else if(zero > maxi){
                    if(middle == false){
                        if(maxi > (zero % 2 + zero / 2)){
                            zero = 0;
                            continue;
                        }
                    }
                    middle = true;
                    maxi = max(zero,maxi);
                } 
                zero = 0;
            }
            // cout << maxi << " " << middle <<  endl;
        }
        if(zero >= maxi){
            middle = false;
            maxi = max(zero,maxi);
        }
        if(middle){
            return max((maxi / 2) + ( maxi % 2),zero);
        }
        return maxi;
    }
};