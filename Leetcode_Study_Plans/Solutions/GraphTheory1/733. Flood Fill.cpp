class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int> > store;
        map<pair<int,int>,bool> visited;
        store.push({sr,sc});
        visited[{sr,sc}] = true;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,-1,1};
        while(!store.empty()){
            int x = store.front().first;
            int y = store.front().second;
            store.pop();
            for(int i = 0; i < 4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX < 0 || newX >= m || newY < 0 || newY >= n || image[newX][newY] != image[x][y] || visited[{newX,newY}]){
                    continue;
                }
                store.push({newX,newY});
                visited[{newX,newY}] = true;
            }
            image[x][y] = newColor;
        }
        return image;
    }  
};