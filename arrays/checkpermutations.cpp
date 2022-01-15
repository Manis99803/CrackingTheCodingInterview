/*
    Given two strings, write a method to decide if one is a permutation of other
*/

#include<bits/stdc++.h>

using namespace std;

bool areStrigsPermutated(string a, string b) {
    // Get strings length
    int aLength = a.length();
    int bLength = b.length();

    // Check for the strings lengths
    if(aLength != bLength) {
        return false;
    }
    // Create frequency array
    vector<int> freq(26, 0);

    // Compute frequency of each character of the a string
    for(int i = 0; i < aLength; i++) {
        freq[a[i] - 97] += 1;
    }


    // Check for the frequncy of each character of stirng b
    for(int i = 0; i < bLength; i++) {
        if(freq[b[i] - 97] > 0) {
            freq[b[i] - 97] -= 1;
        } else {
            if(freq[b[i] - 97] == 0) {
                return false;
            }
        }
    }

    // If the frequency of any of the character is greater than zero. The strings are not anagram.
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string a = "ABCDE";
    string b = "EFCBA";

    cout<<areStrigsPermutated(a, b)<<endl;
    return 0;
}