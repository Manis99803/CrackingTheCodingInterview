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
    vector<int> freq(256, 0);

    // Compute frequency of each character of the a string
    for(int i = 0; i < aLength; i++) {
        freq[a[i]] += 1;
    }


    // Check for the frequncy of each character of stirng b
    for(int i = 0; i < bLength; i++) {
        if(freq[b[i]] > 0) {
            freq[b[i]] -= 1;
        } else {
            if(freq[b[i]] == 0) {
                return false;
            }
        }
    }

    // If the frequency of any of the character is greater than zero. The strings are not anagram.
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            return false;
        }
    }
    return true;
}


bool areStringPermutated(string a, string b) {
    // Get the length of both the strings
    int aLength = a.length();
    int bLength = b.length();

    // Maps for storing the frequency of each string
    unordered_map<int, int> aFreq;
    unordered_map<int, int> bFreq;

    // If the length of the input strings are unequal then return the false
    if(aLength != bLength) {
        return false;
    }
    
    // Get the frequency of each character of string a
    for(int i = 0; i < aLength; i++) {
        aFreq[a[i]] += 1;
    }

    // Get the frequency of each charater of string b
    for(int i = 0; i < bLength; i++) {
        bFreq[b[i]] += 1;
    }

    // Compare the size of map 
    if(aFreq.size() != bFreq.size()) {
        return false;
    }

    // Check if all the characters of first input string is present in the another string or no, also compare the counts
    for(auto it : aFreq) {
        if(bFreq.find(it.first) != bFreq.end()) {
            return false;
        } else {
            if(it.second != bFreq[it.first]) {
                return false;
            }
        }
    }

    return true;
}


// bool areStringPermutated(string a, string b) {
//     // Sort the input a string
//     sort(a.begin(), a.end());
    
//     // Sort the input b string
//     sort(b.begin(), b.end());

//     // If the strings are unequal then
//     if(a != b) {
//         return false;
//     }

//     return true;
// }

int main() {
    string a = "ABCDE";
    string b = "EFCBA";

    cout<<areStrigsPermutated(a, b)<<endl;
    return 0;
}