/*
    Writte an algorithm to such that if an element in a M*N matrix is 0, its entire row and column are set to 0
*/


#include<bits/stdc++.h>

using namespace std;

void zeroMatrix(vector<vector<int> > matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    set<int> rowSet;
    set<int> colSet;

    // Get all the indexes where the value of the element is 0    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(matrix[i][j] == 0) {
                rowSet.insert(i);
                colSet.insert(j);
            }
        }
    }

    // Iterate over row elements and replace all the elements of that row with 0
    for(auto it : rowSet) {
        for(int i = 0; i < r; i++) {
            matrix[it][i] = 0;
        }
    }

    // Iterate over column elements and replace all the elements of that col with 0
    for(auto it : colSet) {
        for(int i = 0; i < c; i++) {
            matrix[i][it] = 0;
        }
    }
}

int main() {
    vector<vector<int> > matrix(3, vector<int>(3, 0));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if((i + 1) * (j + 1) % 2 == 0) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = (i + 1) * (j + 1);
            }
        }
    }

    zeroMatrix(matrix);
    
    

    return 0;
}