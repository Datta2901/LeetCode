


// Do the next Greater element on num2 and store answers in a map
// Now iterate through the second array and push the answers in a vector
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>answer;
        unordered_map<int,int>mp;
        stack<int>store;
        int n = nums2.size();
        for(int i = n - 1; i >= 0; i--){
            while(!store.empty() && store.top() <= nums2[i]){
                store.pop();
            }
            if(store.empty()){
                mp[nums2[i]] = -1;
            }else{
                mp[nums2[i]] = store.top();
            }
            store.push(nums2[i]);
        }
        int m = nums1.size();
        for(int i = 0; i < m; i++){
            answer.push_back(mp[nums1[i]]);
        }
        return answer;
    }
};