//
//  q2_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 30/10/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include<iostream>
#include<climits>
using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

struct Graph {
    int V;
    int E;
    struct Edge *edge;
};

void dijkstra(Graph *g, int source) {
    int u, v, w;
    int d[g->V];
    int p[g->V];
    for (int i = 0; i < g->V; i++) {
        d[i] = INT_MAX;
        p[i] = 0;
    }
    d[source] = 0;
    for(int i = 0; i <= g->V-1; i++) {
        for(int j = 0; j < g->E; j++) {
            u = g->edge[j].u;
            v = g->edge[j].v;
            w = g->edge[j].w;
            
            if(d[u] != INT_MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }
    cout << "\nVertex\t\t:\t";
    for(int i = 0; i < g->V; i ++) {
        cout << i << "\t";
    }
    cout << "\nDistance\t:\t";
    for(int i = 0; i < g->V; i ++) {
        cout << d[i] << "\t";
    }
    cout << "\nParent\t\t:\t";
    for(int i = 0; i < g->V; i ++) {
        cout << p[i] << "\t";
    }
    cout << endl;
}



int main() {
    Graph *g = (Graph*)malloc(sizeof(Graph));
    cout << "\nEnter Number of Vertices\t:\t";
    cin >> g->V;
    cout << "\nEnter Number of Edges\t:\t";
    cin >> g->E;
    g->edge = (Edge*)malloc(g->E*sizeof(Edge));
    cout << "\nEnter Edge (source , destination , weight)\n";
    for ( int i = 0; i < g->E; i++ ) {
        cout << "\nEnter values for " << i+1 << " Edge\n";
        cin >> g->edge[i].u;
        cin >> g->edge[i].v;
        cin >> g->edge[i].w;
    }
    cout << "\nEnter Source Vertex\t:\t";
    int s;
    cin >> s;
    dijkstra(g, s);
    return 0;
}

/*
 Enter Number of Vertices    :    5
 
 Enter Number of Edges    :    9
 
 Enter Edge (source , destination , weight)
 
 Enter values for 1 Edge
 0 1 7
 
 Enter values for 2 Edge
 0 2 2
 
 Enter values for 3 Edge
 1 2 2
 
 Enter values for 4 Edge
 1 3 1
 
 Enter values for 5 Edge
 2 1 3
 
 Enter values for 6 Edge
 2 4 5
 
 Enter values for 7 Edge
 2 3 8
 
 Enter values for 8 Edge
 3 4 4
 
 Enter values for 9 Edge
 4 3 5
 
 Source Vertex    :    0
 Vertex        :    0    1    2    3    4
 Distance      :    0    5    2    6    7
 Parent        :    0    2    0    1    2
*/
