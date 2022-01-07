// Back Tracking
class Solution {
public:
    vector<vector<int> > answer;
    void BackTracking(vector<int>&sub,vector<int> &nums,int start){
        answer.push_back(sub);
        for(int i = start; i < nums.size(); i++){
            if(i > start && nums[i] == nums[i - 1]){
               continue; 
            }
            sub.push_back(nums[i]);
            BackTracking(sub,nums,i + 1);
            sub.pop_back();
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>sub;
        BackTracking(sub,nums,0);
        return answer;
    }
};
