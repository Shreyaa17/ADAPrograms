#include <iostream>
#include <bits/stdc++.h>
using namespace std; 
#define n 10
int V;
int graph[n][n]; 
vector<int> final_ans;
int minimum_key(int key[], bool mstSet[]) { 
    int min = INT_MAX, min_index; 
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
    return min_index; 
} 
vector<vector<int>> MST(int parent[]) { 
    vector<vector<int>> v;
    for (int i = 1; i < V; i++) {
        vector<int> p;
        p.push_back(parent[i]);
        p.push_back(i);
        v.push_back(p);
        p.clear();
    }
    return v;   } 
vector<vector<int>> primMST() { 
    int parent[V]; 
    int key[V];
    bool mstSet[V]; 
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
    key[0] = 0; 
    parent[0] = -1; 
    for (int count = 0; count < V - 1; count++){ 
        int u = minimum_key(key, mstSet); 
        mstSet[u] = true; 
        for (int v = 0; v < V; v++) 
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
    vector<vector<int>> v;
    v = MST(parent);
    return v;  } 
void DFS(int** edges_list,int num_nodes,int starting_vertex,bool* visited_nodes){
    final_ans.push_back(starting_vertex);
    visited_nodes[starting_vertex] = true;
    for(int i=0;i<num_nodes;i++){
        if(i==starting_vertex){
            continue; }
        if(edges_list[starting_vertex][i]==1){
            if(visited_nodes[i]){
                continue; }
            DFS(edges_list,num_nodes,i,visited_nodes);
        } } }
int main() { 
    int j,x,y,sum=0;
    cout<<"Enter the number of cities:"<<endl;
    cin>>V;
    cout<<"Enter the matrix elements :"<<endl;
    for(int i=0;i<V;i++)
    for(int j=0;j<V;j++)
     cin>>graph[i][j];
    vector<vector<int>> v; 
    v = primMST();
    int** edges_list = new int*[V];
    for(int i=0;i<V;i++){
        edges_list[i] = new int[V];
        for(int j=0;j<V;j++){
            edges_list[i][j] = 0; } }
    for(int i=0;i<v.size();i++){
        int first_node = v[i][0];
        int second_node = v[i][1];
        edges_list[first_node][second_node] = 1;
        edges_list[second_node][first_node] = 1; }
    bool* visited_nodes = new bool[V];
    for(int i=0;i<V;i++){
        bool visited_node;
        visited_nodes[i] = false; }
    DFS(edges_list,V,0,visited_nodes);
    final_ans.push_back(final_ans[0]);
    for(int i=0;i<final_ans.size()-1;i++,j++){   j=i+1;
        x=final_ans[i];
        y=final_ans[j];
        sum+=graph[x][y]; }
    for(int i=0;i<final_ans.size();i++){
        cout << final_ans[i]+1 << "-"; }
    cout<<endl;
    cout<<"Cost of the tour is "<<sum<<endl;
    return 0; 
}
