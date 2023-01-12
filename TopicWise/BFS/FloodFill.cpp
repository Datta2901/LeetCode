#include<bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<pair<int,int> >answer;
        queue<pair<int,int> >possibility;
        map<pair<int,int>,int > visited;
        possibility.push({sr,sc});
        while(!possibility.empty()){
            pair<int,int>node =possibility.front();
            if(visited[node] == 0){
                // Up
                if(node.first + 1 < m && node.second < n){
                    if(image[node.first][node.second] == image[node.first + 1][node.second]){
                        possibility.push({node.first + 1,node.second});
                    }
                }
                // Down
                if(node.first - 1 >= 0 && node.first - 1 < m && node.second < n ){
                    if(image[node.first][node.second] == image[node.first - 1][node.second]){
                        possibility.push({node.first - 1,node.second});
                    }
                }

                // Left
                if(node.first  < m && node.second - 1 < n &&  node.second - 1 >= 0){
                    if(image[node.first][node.second] == image[node.first][node.second - 1]){
                        possibility.push({node.first,node.second - 1});
                    }
                }

                // Right
                if(node.first  < m && node.second + 1 < n){
                    if(image[node.first][node.second] == image[node.first][node.second + 1]){
                        possibility.push({node.first,node.second + 1});
                    }
                }
                visited[node] = 1;
                image[node.first][node.second] = newColor;
                // answer.push_back(node);
            }
            possibility.pop();   
        }
        return image;
    }
};



class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int m = image.size(); 
        int n = image[0].size();
        queue<pair<int,int> > track;
        map<pair<int,int>,int>visited;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        visited[{sr,sc}] = 1;
        track.push({sr,sc});
        while(!track.empty()){
            int x = track.front().first;
            int y = track.front().second;
            track.pop();
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(visited[{newX,newY}] == 0){
                    if(newX >= 0 && newX < m && newY >= 0 && newY < n && image[newX][newY] == image[x][y]){
                        track.push({newX,newY});
                        visited[{newX,newY}] = 1;
                    }
                }
            }
            image[x][y] = newColor;
        }
        return image; 
    }  
};

int main(){
    Solution obj;
    int m,n;
    cin >> m >> n;
    vector<vector<int> > image(m),answer;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            int a;
            cin >> a;
            image[i].push_back(a);
        }
    }
    int sr,sc,newcolour;
    cin >> sr >> sc >> newcolour;
    answer = obj.floodFill(image,sr,sc,newcolour);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}