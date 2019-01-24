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
    list<int>* adj;
    
    public:
    Graph(int V);
    void addEdge(int v, int w);
    int BFS(int l);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

int Graph::BFS(int l) {
    int s = 0;
    bool* visited = new bool[V];
    int level[V];
    
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        level[i] = 0;
    }
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    level[s] = 0;
    
    while (!queue.empty()) {
        s = queue.front();
        queue.pop_front();
        for (auto i = adj[s].begin();
             i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                level[*i] = level[s] + 1;
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < V; i++) {
        if (level[i] == l) {
            count++;
        }
    }
    return count;
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
    cout << "\nEnter Level\t:\t";
    cin >> n;
    cout << "\nNumber of Nodes\t:\t" << G.BFS(n);
    cout << endl;
    return 0;
}
