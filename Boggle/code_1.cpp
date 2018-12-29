//
//  code_1.cpp
//  Algorithm
//
//  Created by Mohd Shoaib Rayeen on 23/11/18.
//  Copyright © 2018 Shoaib Rayeen. All rights reserved.
//


#include <iostream>
using namespace std;

#define char_int(c) ((int)c - (int)'A')

#define SIZE (26)

#define M 3
#define N 3

struct TrieNode {
    TrieNode *Child[SIZE];
    bool leaf;
};


TrieNode *getNode() {
    TrieNode * newNode = new TrieNode;
    newNode->leaf = false;
    for (int i =0 ; i< SIZE ; i++) {
        newNode->Child[i] = NULL;
    }
    return newNode;
}


void insert(TrieNode *root, char *Key) {
    size_t n = strlen(Key);
    TrieNode * pChild = root;
    
    for (int i = 0; i < n; i++) {
        int index = char_int(Key[i]);
        if (pChild->Child[index] == NULL) {
            pChild->Child[index] = getNode();
        }
        pChild = pChild->Child[index];
    }
    pChild->leaf = true;
}


bool isSafe(int i, int j, bool visited[M][N]) {
    return (i >=0 && i < M && j >=0 && j < N && !visited[i][j]);
}

void searchWord(TrieNode *root, char boggle[M][N], int i, int j, bool visited[][N], string str) {
    if (root->leaf == true) {
        cout << str << endl ;
    }
    if (isSafe(i, j, visited)) {
        visited[i][j] = true;
        for (int K =0; K < SIZE; K++) {
            if (root->Child[K] != NULL) {
                char ch = (char)K + (char)'A' ;
                if (isSafe(i+1,j+1,visited) && boggle[i+1][j+1] == ch) {
                    searchWord(root->Child[K],boggle,i+1,j+1,visited,str+ch);
                }
                if (isSafe(i, j+1,visited)  && boggle[i][j+1] == ch) {
                    searchWord(root->Child[K],boggle,i, j+1,visited,str+ch);
                }
                if (isSafe(i-1,j+1,visited) && boggle[i-1][j+1] == ch) {
                    searchWord(root->Child[K],boggle,i-1, j+1,visited,str+ch);
                }
                if (isSafe(i+1,j, visited)  && boggle[i+1][j] == ch) {
                    searchWord(root->Child[K],boggle,i+1, j,visited,str+ch);
                }
                if (isSafe(i+1,j-1,visited) && boggle[i+1][j-1] == ch) {
                    searchWord(root->Child[K],boggle,i+1, j-1,visited,str+ch);
                }
                if (isSafe(i, j-1,visited)&& boggle[i][j-1] == ch) {
                    searchWord(root->Child[K],boggle,i,j-1,visited,str+ch);
                }
                if (isSafe(i-1,j-1,visited) && boggle[i-1][j-1] == ch) {
                    searchWord(root->Child[K],boggle,i-1, j-1,visited,str+ch);
                }
                if (isSafe(i-1, j,visited) && boggle[i-1][j] == ch) {
                    searchWord(root->Child[K],boggle,i-1, j, visited,str+ch);
                }
            }
        }
        visited[i][j] = false;
    }
}

void findWords(char boggle[M][N], TrieNode *root) {
    bool visited[M][N];
    memset(visited,false,sizeof(visited));
    
    TrieNode *pChild = root ;
    
    string str = "";
    for (int i = 0 ; i < M; i++) {
        for (int j = 0 ; j < N ; j++) {
            if (pChild->Child[char_int(boggle[i][j])] ) {
                str = str+boggle[i][j];
                searchWord(pChild->Child[char_int(boggle[i][j])], boggle, i, j, visited, str);
                str = "";
            }
        }
    }
}

int main() {
    char *dictionary[] = {"GEEKS", "FOR", "QUIZ", "GEE"};
    TrieNode *root = getNode();
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i=0; i<n; i++) {
        insert(root, dictionary[i]);
    }
    char boggle[M][N] = {
        {'G','I','Z'},
        {'U','E','K'},
        {'Q','S','E'}
    };
    
    findWords(boggle, root);
    return 0;
}
