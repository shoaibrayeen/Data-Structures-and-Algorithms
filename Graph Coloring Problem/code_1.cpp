//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#define V 4

void printSolution(int color[]);

bool isSafe (int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V) {
        return true;
    }
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil (graph, m, color, v+1) == true) {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[V][V], int m) {
    int *color = new int[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }
    if (graphColoringUtil(graph, m, color, 0) == false) {
        printf("\nSolution does not exist\n");
        return false;
    }
    printSolution(color);
    return true;
}

void printSolution(int color[]) {
    cout << "\nSolution Exists\n";
    cout << "--------------------";
    cout << "\nVertex\t|\tColor\n";
    cout << "--------------------\n";
    for (int i = 0; i < V; i++) {
        cout << "\t" << (i+1) << "\t|\t" << color[i];
        cout << endl;
    }
    cout << "--------------------\n";
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    graphColoring (graph, m);
    return 0;
}
