class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int answer = 0;
        map<int,int>mp;
        for(auto it : nums1){
            for(auto i : nums2){
                mp[it + i]++;
            }
        }
        for(auto it : nums3){
            for(auto i : nums4){
                answer += mp[0 - it - i];
            }
        }
        return answer;
    }
};
