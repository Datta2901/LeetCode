#include<bits/stdc++.h>
using namespace std;

class Solution {
    int getDistance(int x1,int y1,int x2,int y2){
        return round(sqrt(pow(x1 - x2,2) + pow(y1 - y2,2)));
    }
public:
    int nearestValidPoint(int x, int y, vector<vector<int> >& points) {
        int mini =INT_MAX;
        int answer = -1;
        int n = points.size();
        for(int i = 0; i < n; i++){
            if(x == points[i][0] || y == points[i][1]){
                int dis = getDistance(x,y,points[i][0],points[i][1]);
                // cout << dis << " ";
                if(dis < mini){
                    mini = dis;
                    answer = i;
                }
            }
        }
        return answer;
    }
};


int main(){
    Solution obj;
    int x,y;
    cin >> x >> y;
    int size;
    cin >> size;
    vector<vector<int> >num;
    for(int i = 0; i < size; i++){
        int a,b;
        cin >> a >> b;
        num.push_back({a,b});
    }
    cout << obj.nearestValidPoint(x,y,num) << endl;

    return 0;
}