#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
        double findMedianSortedArrays(vector<int>num1,vector<int>num2){
            if(num1.size() > num2.size()){
                return findMedianSortedArrays(num2,num1);
            }
            int n1 = num1.size();
            int n2 = num2.size();
            // since doing binary search on smaller array
            int low = 0,high = n1;
            while(low <= high){
                int cut1 = low + (high - low) / 2; //taking half elements on left half
                int cut2 = (n1 + n2 + 1) / 2 - cut1 ; //total - elements in left half
                // if we are not picking anything then simply assignment int max and min
                int left1 = (cut1 == 0) ? INT_MIN : num1[cut1 - 1];
                int left2 = (cut2 == 0) ? INT_MIN : num2[cut2 - 1];
                int right1 = (cut1 == n1) ? INT_MAX : num1[cut1];
                int right2 = (cut2 == n2) ? INT_MAX : num2[cut2];

                if(left1 <= right2  && left2 <= right1){
                    // if the total size is even 
                    if((n1 + n2) % 2 == 0){
                        return (max(left1 ,left2) + min(right1,right2)) / 2.0; 
                    }else{
                        return max(left1,left2);
                    }
                }else if(left1 > right2){
                    high = cut1 - 1;
                }else{
                    low = cut1 + 1;
                }
            }
            return 0.0;
        } 
};


vector<int> GetInput(int n){
    vector<int> answer;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        answer.push_back(a);
    }
    return answer;
}

int main(){
    Solution obj;
    int n1,n2;
    cin >> n1 >> n2;
    vector<int> num1,num2;
    num1 = GetInput(n1);
    num2 = GetInput(n2);
    cout << obj.findMedianSortedArrays(num1,num2) << endl;
    return 0;
}