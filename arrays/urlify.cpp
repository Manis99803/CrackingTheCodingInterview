/*
    Write a program to replace all the spaces in the string with '%20'. You may assume that the string has sufficient space at the end.
*/
#include<bits/stdc++.h>

using namespace std;

int getStringEndIndex(char str[], int strLength) {
    /*
        Get the end index of a character in the string, there after which we have only white spaces
    */
    int i = strLength - 2;
    while(str[i] == 32) {
        i -= 1;
    }
    return i;
}

void replaceSpaceWithPattern(char str[], char pattern[], int strEndIndex, int endIndex, int patternLength) {
    /*
        replace space with the pattern
    */

    int i = strEndIndex;
    while(i >= 0) {
        if(str[i] != 32) {
            str[endIndex] = str[i];
            endIndex -= 1;
        } else {
            for(int i = patternLength - 1; i >= 0; i--) {
                str[endIndex] = pattern[i];
                endIndex -= 1;
            }
        }
        i -= 1;
    }
}

int main() {
    char str[] = "Mr John Smith    ";
    char pattern[] = "%20";
    
    int strLength = sizeof(str) / sizeof(str[0]);
    int endIndex = strLength - 2; // - 1, would point to the null character
    
    int patternLength = (sizeof(pattern) / sizeof(pattern[0])) - 1;

    int strEndIndex = getStringEndIndex(str, strLength);
    replaceSpaceWithPattern(str, pattern, strEndIndex, endIndex, patternLength);

    int i = 0;
    while(i <= endIndex) {
        cout<<str[i]<<endl;
        i += 1;
    }
    
    return 0;
}