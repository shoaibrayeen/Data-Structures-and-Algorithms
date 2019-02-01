//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;
#define N 8

int solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[],  int yMove[]);


bool isSafe(int x, int y, int sol[N][N]) {
    return ( x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}


void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            cout <<  sol[x][y] << " ";
        }
        cout << endl;
    }
}


void solveKT() {
    int sol[N][N];
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            sol[x][y] = -1;
        }
    }
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
    sol[0][0]  = 0;
    if (solveKTUtil(0, 0, 1, sol, xMove, yMove) == false) {
        cout << "\nSolution does not exist\n";
        return;
    }
    else {
        cout  << "\nSolution Exists for 8*8 Square\n";
        printSolution(sol);
    }
}

int solveKTUtil(int x, int y, int movei, int sol[N][N],int xMove[N], int yMove[N]) {
    int next_x, next_y;
    if (movei == N*N) {
        return true;
    }
    for (int k = 0; k < 8; k++) {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei+1, sol, xMove, yMove) == true) {
                return true;
            }
            else {
                sol[next_x][next_y] = -1;
            }
        }
    }
    return false;
}

int main() {
    solveKT();
    return 0;
}
