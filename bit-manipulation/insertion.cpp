/*
    Insertion: You are given two 32-bit numbers, N and M, and two positions, i and j. Write a method to insert M into N such that M starts at bit j and ends at bit i.
    You can assume that there are at least 5 bts between j and i. You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and 2

    Input: 
    N = 10000000000
    M = 10011

    j = 6
    i = 2

    = 10001001100
*/

#include<bits/stdc++.h>

using namespace std;

// Function is given the input m, n, j, i

int fitMinN(int m, int n, int j, int i) {
    string numInBitFormat;

    int mValue = m;
    while(mValue > 0) {
        int value = mValue % 2;
        cout<<value<<endl;
        mValue = mValue / 2;
    }
    while(n > 0) {
        int value = n % 2;
        numInBitFormat += to_string(value);
        n = n / 2;
    }

    int size = numInBitFormat.length();

    for(int i = 0; i < size; i++) {
        if(numInBitFormat[i] == '1') {
            m |= (1 << j);
        } else {
            m &= ~(1 << j);
        }
        j -= 1;
    }

    while(m > 0) {
        int value = m % 2;
        cout<<value<<endl;
        m = m / 2;
    }

    return m;
}


int main() {
    int m = 1024;
    int n = 19;
    
    cout<<fitMinN(m, n, 6, 2)<<endl;
    return 0;
}
