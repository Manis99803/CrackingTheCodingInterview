/*
    There are three types of edits that can be performed on strings: insert, remove, replace a character. Given two strings, write a function to check 
    if they are one edit(or zero edits) away.
    Ex:
    pale, ple -> True
    pales, palse -> True
    pale, bale -> True
    pale, bake -> False
*/

#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

bool areStringOneEditAway(string a, string b) {
    // Get the length of the two strings
    int aLength = a.length();
    int bLength = b.length();

    if(abs(bLength - aLength ) > 1) {
        return false;
    }

    int numberOfDifferenceCharacters = 0;

    int i = 0;
    int j = 0;

    // Start iterating over both the strings
    while(i < aLength && j < bLength) {
        if(a[i] == b[j]) {
            i += 1;
            j += 1;
        } else {
            // If the characters don't match

            // If the length of the first string is greater than the second one, increment the first one else increment the second one
            if(aLength > bLength) {
                i += 1;
            } else if(aLength < bLength) {
                j += 1; 
            } else {
                i += 1;
                j += 1;
            }
            numberOfDifferenceCharacters += 1;
        }
    }

    // If last character is extra in any string
    if(i < aLength or j < bLength) {
        numberOfDifferenceCharacters += 1;
    }

    return numberOfDifferenceCharacters == 1;
}

int main() {
    string a = "pale";
    string b = "bake";

    cout<<areStringOneEditAway(a, b)<<endl;
    return 0;
}