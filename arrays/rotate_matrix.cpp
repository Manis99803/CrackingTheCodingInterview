/*
    Rotate Matrix: Given an image represented by N*N matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees. 
    Can you do this in place?
*/

#include<bits/stdc++.h>

using namespace std;

void rotateMatrix(vector<vector<int> > &matrix) {
    // Get the row size of a matrix
    int r = matrix.size();

    // Get the column size of a matrix
    int c = matrix[0].size();

    // transform the matrix
    for(int i = 0; i < r; i++) {
        for(int j = i + 1; j < c; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row of a matrix
    for(int i = 0; i < r; i++) {
        int j = 0;
        int k = c - 1;
        while(j < k) {
            swap(matrix[i][j], matrix[i][k]);
            j += 1;
            k -= 1;
        }
    }
}


int main() {
    vector<vector<int> > matrix(3, vector<int>(3, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }

    rotateMatrix(matrix);
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}