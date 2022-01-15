/*
    Implement an algorithm to dertemine if a string has all unique characters. What if you cannot use extra data structure
*/

#include<bits/stdc++.h>
using namespace std;

// bool doesStringHaveUniqueCharacters(string s) {
//     // Initialize a vector for storing the frequency of each character of the input string
//     vector<int> freq(26, 0);
//     int length = s.length();

//     // Compute the frequency of each character of the input string
//     for(int i = 0; i < length; i++) {
//         freq[s[i]] += 1;
//     }

//     // Check if the frequency is greater than 1 of any character
//     for(int i = 0; i < length; i++) {
//         if(freq[s[i]] > 1) {
//             return false;
//         }
//     }
//     return true;
// }


// bool doesStringHaveUniqueCharacters(string s) {
//     // Get the string length
//     int length = s.length();

//     // Iterate over each character and get the frequency of each character
//     for(int i = 0; i < length; i++) {
//         int freq = 0;
//         for(int j = 0; j < length; j++) {
//             if(s[i] == s[j]) {
//                 freq += 1;
//             }
//         }
//         // If the frequency is greater than 1, then the string have duplicate characters
//         if(freq > 1) {
//             return false;
//         }
//     }
//     return true;
// }

bool doesStringHaveUniqueCharacters(string s) {
    // Since all the characters of the input string are  A - Z, all the bits of charBitSet is assigned to 0
    int  charBitSet = 0;
    int length = s.length();

    for(int i = 0; i < length; i++) {
        int bitAtIndex = s[i] - 'A';

        // If that bit is already set in the charBitSet then return false
        if(charBitSet & (1 << bitAtIndex)) {
            return false;
        }

        // Else update the chatBitSet by setting that bit
        charBitSet = charBitSet | (1 << bitAtIndex);
    }
    return true;
}

int main() {
    string s = "ABCEE";
    cout<<doesStringHaveUniqueCharacters(s)<<endl;

    return 0;
}
