#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
        int GetAnswer(vector<int>& nums,int k){
            unordered_map<int,int>fre;
            int answer = 0;
            int i = 0;
            for(int j = 0; j < nums.size(); j++){
                fre[nums[j]]++;
                while(fre.size() > k){
                    fre[nums[i]] -= 1;
                    if(fre[nums[i]] == 0){
                        fre.erase(nums[i]);
                    }
                    i++;
                }
                answer += (j - i + 1); 
            }
            return answer;
        }
    public:
        int subarraysWithKDistinct(vector<int>& nums, int k) {
            return GetAnswer(nums,k) - GetAnswer(nums,k - 1);
        }
};

int main(){
    Solution obj;
    string nums;
    cin >> nums;
    cout << obj.countVowelSubstrings(nums) << endl;

    return 0;
}