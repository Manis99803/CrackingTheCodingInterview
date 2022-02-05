/*
    Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes
*/

#include<bits/stdc++.h>

using namespace std;

// Function which checks if there exist a path between the source and the destination
bool doesPathExist(vector<vector<int>> &graph, int source, int destination, vector<bool> &visited) {
    // If the source and destination are same then there exist a path between the two nodes
    if(source == destination) {
        return true;
    }

    // else mark the node as visited
    visited[source] = true;
    
    // start traversing the source array
    for(auto it : graph[source]) {
        if(doesPathExist(graph, it, destination, visited)) {
            return true;
        }
    }
    return false;
}

// Function for checking if a path exist between soure and destination
bool validPath(int n, vector<vector<int>> edges, int source, int destination) {
    vector<vector<int>> graph(n, vector<int>());
    int edgeSize = edges.size();

    // Form a graph out of the edges given
    for(int i = 0; i < edgeSize; i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    // Vector to keep track of the nodes which are visited and nodes which are not
    vector<bool> visited(n, false);

    // Function for checking if there exist a path between source and destination
    return doesPathExist(graph, source, destination, visited);
}