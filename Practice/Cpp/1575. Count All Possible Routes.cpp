#include <bits/stdc++.h>
using namespace std;


class Solution1 {
private:
    int mod = int(1e9) + 7;
    int getAnswer(vector<int>&locations,int finish,int fuel,int index){
        if(index >= locations.size()){
            return 0;
        }
        if(fuel < 0){
            return 0;
        }
        int answer = 0;
        if(finish == index){
            answer++;
        }
        cout << answer << endl;
        for(int i = index + 1; i < locations.size(); i++){
            if(i != index){
                answer += getAnswer(locations,finish,fuel - abs(locations[i] - locations[index]),i);
                answer = answer % mod;
            }
        }
        return answer;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
       return getAnswer(locations,finish,fuel,start);
    }
};

int main(){
    Solution obj;
    int size;
    cin >> size;
    vector<int>nums;
    for(int i = 0; i < size; i++){
        int a;
        cin >> a;
        nums.push_back(a);
    }
    int start,finish,fuel;
    cin >> start >> finish >> fuel;
    cout << obj.countRoutes(nums,start,finish,fuel) << endl;
}