/*
    Implement a method to perform basci string compression using the counts of repeated characters. For example, the string
    aabcccccaaa would become a2b1c5a3. If the compressed string would not become smaller than the original string, your method should return the original string.
    You can assume that string has only the uppercase and lowercase letters (a-z)

    Input: "aabcccccaaa"
    Output: a2b1c5a3
*/

#include<bits/stdc++.h>

using namespace std;

string compressString(string a) {
    // Get the length of the input string
    int length = a.length();

    // variable which will hold the compressed string
    string compressedString;
    
    // Create two pointer i and j
    int i = 0;
    int j = 0;
    
    while(i < length) {
        j = i + 1;
        int count = 1;
        // Keep iterating till a[i] and a[j] are equal
        while(j < length and a[i] == a[j]) {
            count += 1;
            j += 1;
        }
        compressedString += a[i] + to_string(count);
        i = j;
    }
    return compressedString;
}

int main() {
    string str = "abcd";

    cout<<compressString(str)<<endl;
    return 0;
}