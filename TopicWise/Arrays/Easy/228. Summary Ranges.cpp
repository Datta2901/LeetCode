// class Solution {
// public:
//     vector<string> summaryRanges(vector<int>& nums) {
//         vector<string>answer;
//         if(nums.size() == 0){
//             return answer;
//         }
//         int start = nums[0];
//         int n = nums.size();
//         for(int i = 1; i < n; i++){
//             if(nums[i - 1] + 1 != nums[i]){
//                 if(start == nums[i - 1]){
//                     answer.push_back(to_string(start));
//                 }else{
//                     answer.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
//                 }
//                 start = nums[i];
//             }
//         }
        
//         if(start == nums[n - 1]){
//             answer.push_back(to_string(start));
//         }else{
//             answer.push_back(to_string(start) + "->" + to_string(nums[n - 1]));
//         }
//         return answer;
//     }
// };

