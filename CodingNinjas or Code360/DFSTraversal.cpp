//Link : https://www.naukri.com/code360/problems/dfs-traversal_630462

#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

void dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int> >& adjList, vector<int>& component){
    //component stores the answer which is going to the main function to be returned to the final answer
    component.push_back(node);
    visited[node] = true;

    //now we will call recursive call for every connected node
    for(auto i : adjList[node]){
        if(!visited[i]){
            dfs(i, visited, adjList, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //prepare adjList
    unordered_map<int, list<int> > adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //prepare visited map
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;

    for(int i=0; i<V; i++){
        if(!visited[i]){
        vector<int> component;    //array in which we will store the ans from dfs 
            dfs(i, visited, adjList, component);
            ans.push_back(component);
        }
    } 
    return ans;
}

int main(){
    int V, E;
    cin>>V>>E;
    vector<vector<int>> edges;
    for(int i=0; i<E; i++){
        int u, v;
        cin>>u>>v;
        edges.push_back({u, v});
    }

    vector<vector<int>> ans = depthFirstSearch(V, E, edges);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;   
}