/*
    Build Order: You are given a list of projects and list of all dependencies(which is a list of pairs of projects, where the second project is dependent on the first project).
    All of a project's dependencies must be built before the project is. Find a build order that will allow the projects to be built. If there is no valid build order, return an error

    projects: a, b, c, d, e, f
    dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)

    Output: f, e, a, b, d, c
*/

#include<bits/stdc++.h>

using namespace std;

// Function doing DFS
void DFS(int source, vector<bool> visited, vector<int> adj[], stack<int> st) {
    visited[source] = false;
    for(auto it : adj[source]) {
        if(!visited[it]) {
            DFS(it, visited, adj, st);
        }
    }
    st.push(source);
}

// Function which returns topological sorting of an input graph
vector<int> topoSort(int V, vector<int> adj[]) {
    // stack for storing the topological sorting of the graph
    stack<int> st;
    // vector for keeping track of the nodes which are already visited
    vector<bool> visited(V, false);
    
    vector<int> elements;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            DFS(i, visited, adj, st);
        }
    }

    // Displays the topological sorting of the input graph
    while(!st.empty()) {
        cout<<st.top()<<endl;
        st.pop();
    }
}