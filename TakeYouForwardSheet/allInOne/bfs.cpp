#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int>adj[vertex + 1];
    for(auto it : edges){
        int u = it.first;
        int v = it.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>store;
    vector<int>answer;
    vector<bool>visited(vertex + 1,false);
    for(int i = 0; i < vertex; i++){
        if(!visited[i]){
            store.push(i);
            answer.push_back(i);
            visited[i] = true;
            vector<int>level;
            while(!store.empty()){
                int u = store.front();
                store.pop();
                for(auto it : adj[u]){
                     if(!visited[it]){
                        visited[it] = true;
                        level.push_back(it);
                        store.push(it);
                     }
                }
                sort(level.begin(),level.end());;
                answer.insert(answer.end(),level.begin(),level.end());
                level.clear();
            } 
        }
    }
    return answer;
}

int main(){
    int size;
    cin >> size;
    vector<pair<int,int>> edges; 
    for(int i = 0; i < size; i++){
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }
    vector<int>answer = BFS(size,edges);
    for(auto it : answer){
        cout << it << " ";
    }
    return 0;
}