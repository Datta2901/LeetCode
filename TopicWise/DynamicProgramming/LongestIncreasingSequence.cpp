// int getAnswer(vector<vector<int> > &matrix,pair<int,int> source,vector<vector<int> > &visited){
//     int m = matrix.size();
//     int n = matrix[0].size();
//     int answer = 1; // including present cell
//     queue<pair<int,int> >store;
//     store.push(source);
//     visited[source.first][source.second] = 1;
//     int dx[4] = {0,0,1,-1};
//     int dy[4] = {-1,1,0,0};
//     while(!store.empty()){
//         pair<int,int> node = store.front();
//         store.pop();
//         answer++;
//         vector<vector<int> > order;
//         for(int i = 0; i < 4; i++){
//             int newX = node.first + dx[i];
//             int newY = node.second + dy[i];
//             if(newX < 0 || newY < 0 || newX >= m || newY >= n || visited[newX][newY] == 1){ 
//                 continue;
//             }
//             if(matrix[node.first][node.second] < matrix[newX][newY]){
//                 cout <<" {" << newX << " " << newY << "} ";
//                 order.push_back({matrix[newX][newY],newX,newY});
//                 visited[newX][newY] = 1;
//             }
//         }
//         sort(order.begin(),order.end());
//         for(auto it : order){
//             store.push({it[1],it[2]});
//         }
//     }
//     return answer;
// }

// int solve(vector<vector<int>>& matrix) {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     int answer = INT_MIN;
//     for(int i = 0; i < m; i++){
//         vector<vector<int> > visited(m,vector<int>(n,0));
//         for(int j = 0; j < n; j++){
//             cout << i  << " " << j << " [ " ;
//             int a = getAnswer(matrix,{i,j},visited);
//             answer = max(answer,a);
//             cout << "] size :  " << a << endl;
//         }
//     }
//     return answer;
// }




// int getAnswer(vector<vector<int> > &matrix,pair<int,int> source,vector<vector<int> > &visited){
//     int m = matrix.size();
//     int n = matrix[0].size();
//     int answer = 1; // including present cell
//     stack<pair<int,int> >store;
//     store.push(source);
//     visited[source.first][source.second] = 1;
//     int dx[4] = {0,0,1,-1};
//     int dy[4] = {-1,1,0,0};
//     while(!store.empty()){
//         pair<int,int> node = store.top();
//         store.pop();
//         answer++;
//         vector<vector<int> > order;
//         for(int i = 0; i < 4; i++){
//             int newX = node.first + dx[i];
//             int newY = node.second + dy[i];
//             if(newX < 0 || newY < 0 || newX >= m || newY >= n || visited[newX][newY] == 1){ 
//                 continue;
//             }
//             if(matrix[node.first][node.second] < matrix[newX][newY]){
//                 cout <<" {" << newX << " " << newY << "} ";
//                 order.push_back({matrix[newX][newY],newX,newY});
//                 visited[newX][newY] = 1;
//             }
//         }
//         sort(order.begin(),order.end());
//         for(auto it : order){
//             store.push({it[1],it[2]});
//         }
//     }
//     return answer;
// }

// int solve(vector<vector<int>>& matrix) {
//     int m = matrix.size();
//     int n = matrix[0].size();
//     int answer = INT_MIN;
//     for(int i = 0; i < m; i++){
//         vector<vector<int> > visited(m,vector<int>(n,0));
//         for(int j = 0; j < n; j++){
//             cout << i  << " " << j << " [ " ;
//             int a = getAnswer(matrix,{i,j},visited);
//             answer = max(answer,a);
//             cout << "] size :  " << a << endl;
//         }
//     }
//     return answer;
// }

int getAnswer(int i,int j,vector<vector<int> > &matrix,vector<vector<int> > &dp,int m,int n){
    if(i < 0 || j < 0 || i >= m || j >= n){ 
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int count = 1;
    for(int k = 0; k < 4; k++){
        int newX = i + dx[k];
        int newY = j + dy[k];
        if(newX < 0 || newY < 0 || newX >= m || newY >= n){         
            continue;
        }
        if(matrix[newX][newY] > matrix[i][j]){
            count = max(count,1 + getAnswer(newX,newY,matrix,dp,m,n));
        }
        dp[i][j] = max(count,dp[i][j]);
    }
    
    return dp[i][j];
}

int solve(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int answer = INT_MIN;
    vector<vector<int> > dp(m + 1,vector<int>(n + 1,-1));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            answer  = max(answer,getAnswer(i, j,matrix,dp,m,n));
        }
    }
    if(answer == -1){
        return 1;
    }
    
    return answer;
}