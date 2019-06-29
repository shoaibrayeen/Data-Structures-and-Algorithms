
//
//  code_2.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <string>
#include <iostream>
using namespace std;

#define M 3
#define N 3

string dictionary[] = { "GEEKS", "FOR", "QUIZ", "GO" };
int n = sizeof(dictionary) / sizeof(dictionary[0]);


bool isWord(string& str) {
    for (int i = 0; i < n; i++) {
        if (str.compare(dictionary[i]) == 0) {
            return true;
        }
    }
    return false;
}

void findWordsUtil(char boggle[M][N], bool visited[M][N], int i, int j, string& str) {
    visited[i][j] = true;
    str = str + boggle[i][j];
    if (isWord(str)) {
        cout << str << endl;
    }
    for (int row = i - 1; row <= i + 1 && row < M; row++) {
        for (int col = j - 1; col <= j + 1 && col < N; col++) {
            if (row >= 0 && col >= 0 && !visited[row][col]) {
                findWordsUtil(boggle, visited, row, col, str);
            }
        }
    }
    str.erase(str.length() - 1);
    visited[i][j] = false;
}

void findWords(char boggle[M][N]) {
    bool visited[M][N];
    memset(visited,false,sizeof(visited));
    string str = "";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++ ) {
            findWordsUtil(boggle, visited, i, j, str);
        }
    }
}

int main() {
    char boggle[M][N] = {
        { 'G', 'I', 'Z' },
        { 'U', 'E', 'K' },
        { 'Q', 'S', 'E' }
    };
    
    cout << "\nWords of dictionary\n";
    findWords(boggle);
    return 0;
}
