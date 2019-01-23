//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include<iostream>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}
void Graph::DFS(int v) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    DFSUtil(v, visited);
}

int main() {
    cout << "\nEnter Number of Vertex\t:\t";
    int n;
    cin >> n;
    Graph G(n);
    int s;
    cout << "\nEnter Edge Details (source , destination) ||  For Exit -> Enter -1 for Source\n";
    while(true) {
        cout << "\nEnter Source\t:\t";
        cin >> n;
        if (n == -1) {
            break;
        }
        cout << "\nEnter Destination\t:\t";
        cin >> s;
        G.addEdge(n, s);
    }
    cout << "\nEnter Start Point\t:\t";
    cin >> s;
    cout << "\nDFS\t:\t";
    G.DFS(s);
    cout << endl;
    return 0;
}
