/* 
    Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. 
    A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.

    Input: Tact Coa
    Output: True (permutation: "taco cat", "atco cta", etc.,)
*/

#include<bits/stdc++.h>
#include <unordered_map>

using namespace std;

bool isPermutationOfPalindrome(string a) {
    // Get the length of the input string
    int length = a.length();

    // Map for getting the frequency of each character
    unordered_map<int, int> afreq;

    // Iterate the input string and get the frequency of each element
    for(int i = 0; i < length; i++) {
        afreq[a[i]] += 1;
    }

    int numberOfEven = 0;
    int numberOfOdd = 0;

    // Check number of characters repeating odd number of times
    for(auto it : afreq) {
        if(it.second % 2 == 0) {
            numberOfEven += 1;
        } else {
            numberOfOdd += 1;
        }
    }

    // If the number of items repeating odd number of times is more than 1, which it is not a permutation of palindrome
    if(numberOfOdd > 1) {
        return false;
    }
    return true;
}


int main() {
    string str = "Tact Coa";
    cout<<isPermutationOfPalindrome(str)<<endl;
    return 0;
}
