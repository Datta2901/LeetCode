#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>answer;
        map<int,int> fre;
        for(auto it : nums1){
            fre[it]++;
        }
        for(int i = 0; i < nums2.size(); i++){
            if(fre[nums2[i]]){
                answer.push_back(nums2[i]);
                fre[nums2[i]]--;
            }
        }
        return answer;
    }
};


int main(){
    Solution obj;
    vector<int> nums1,nums2;
    int size;
    cin >> size;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums1.push_back(a);
    }
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums2.push_back(a);
    }
    vector<int> answer = obj.intersect(nums1,nums2);
    for(int i = 0; i < size; i++){
        cout  <<  answer[i] << " ";
    }
    return 0;
}