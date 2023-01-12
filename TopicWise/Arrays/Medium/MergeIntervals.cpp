#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     vector<vector<int> > merge(vector<vector<int> >& intervals) {
//        vector<vector<int> > answer;
//         sort(intervals.begin(),intervals.end());
//         int start = intervals[0][0],end = intervals[0][1],pos = 0;
//         for(int i = 1; i < intervals.size(); i++){
//             if(start <= intervals[i][0] && intervals[i][0] <= end){
//                 if(end < intervals[i][1]){
//                     end = intervals[i][1];
//                 }
//             }else{
//                 answer.push_back({start,end});
//                 start = intervals[i][0];
//                 end = intervals[i][1];
//             }
//         } 
//         answer.push_back({start,end});
//         return answer;
//     }
// };

class Solution {
public:
    int merge(vector<vector<int> >& intervals) {
       vector<vector<int> > answer;
        sort(intervals.begin(),intervals.end());
        int start = intervals[0][0],end = intervals[0][1],pos = 0;
        for(int i = 1; i < intervals.size(); i++){
            if(start <= intervals[i][0] && intervals[i][0] <= end){
                if(end < intervals[i][1]){
                    end = intervals[i][1];
                }
            }else{
                answer.push_back({start,end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        } 
        answer.push_back({start,end});
        return answer.size();
    }
};

int main(){
    Solution obj;
    int size;
    cin >> size;
    vector<vector<int> >answer(size);
    for(int i = 0; i < size; i++){
        int a,b;
        cin >> a >> b;
        answer[i].push_back(a);
        answer[i].push_back(b);
    }
    int a = obj.merge(answer);
    cout << a << endl;
    return 0; 
}