//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 15/04/19.
//  Copyright © 2019 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;
#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, bool sol[N][N]);

void printSolution(bool sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << "\t";
        }
        cout << "\n";
    }
}

bool isSafe(int maze[N][N], int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) {
        return true;
    }
    return false;
}

bool solveMaze(int maze[N][N]) {
    bool sol[N][N] = {
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 } };
    
    if (solveMazeUtil(maze, 0, 0, sol) == false) {
        cout << "\nSolution doesn't exist.";
        return false;
    }
    cout << "\nSolution Path\n";
    printSolution(sol);
    return true;
}

bool solveMazeUtil(int maze[N][N], int x, int y, bool sol[N][N]) {
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafe(maze, x, y) == true) {
        sol[x][y] = 1;
        if (solveMazeUtil(maze, x + 1, y, sol) == true) {
            return true;
        }
        if (solveMazeUtil(maze, x, y + 1, sol) == true) {
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    
    return false;
}

int main() {
    int maze[N][N] = {
        { 1, 0, 0, 0 },
        { 1, 1, 0, 1 },
        { 0, 1, 0, 0 },
        { 1, 1, 1, 1 } };
    
    solveMaze(maze);
    return 0;
}
