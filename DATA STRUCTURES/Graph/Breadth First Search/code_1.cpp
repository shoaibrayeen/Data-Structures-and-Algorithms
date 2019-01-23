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
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;
    
    while(!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
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
    cout << "\nBFS\t:\t";
    G.BFS(s);
    cout << endl;
    return 0;
}
