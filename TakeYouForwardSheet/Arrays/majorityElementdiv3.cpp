class Solution {
public:
    vector<int> majorityElement(vector<int>& A) {
        
        int ele1 = INT_MAX,ele2 = INT_MIN,n = A.size();
        int answer = n/3;
        int count1 = 0,count2 = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == ele1){
                count1++;
            }else if(A[i] == ele2){
                count2++;
            }else if(count1 == 0){
                ele1 = A[i];
                count1 += 1;
            }else if(count2 == 0){
                ele2 = A[i];
                count2 += 1;
            }else{
                count1 -= 1;
                count2 -= 1;
            }
        }
        vector<int>aa;

        if(count1 == 0 && count2 == 0){
            return aa;
        }
        count1 = 0,count2 = 0;
        for(int i = 0; i < n; i++){
            if(A[i] == ele1){
                count1++;
            }else if(A[i] == ele2){
                count2++;
            }
        }
        if(count1 > answer){
            aa.push_back(ele1);
        }if(count2 > answer){
           aa.push_back(ele2);
        }
        return aa;
    }
};