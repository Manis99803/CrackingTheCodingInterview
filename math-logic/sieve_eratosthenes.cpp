/*
    Given a number n count number of prime number less than n
*/

#include<bits/stdc++.h>

using namespace std;

// Function for crossing of the number divisible by prime number
void crossOff(vector<bool> flags, int n, int prime) {
    for(int i = prime * prime; i <= n; i += prime) {
        flags[i] = false;
    }
}

// Function to get next prime number
int getNextPrime(vector<bool> flags, int n) {
    for(int i = 2; i <= n; i++) {
        if(flags[i]) {
            return i;
        }
    }
    return n;
}

// Function to count number of prime numbers below n
int countPrimeNumber(int n) {
    vector<bool> flags(n + 1, true);

    int prime = 2;

    // Cross off all the numbers divisible by prime
    while(prime <= sqrt(n)) {
        crossOff(flags, n);
        prime = getNextPrime(flags, n);
    }

    // variable for storing the number of prime number count
    int count = 0;

    // Count the number of prime
    for(int i = 2; i <= n; i++) {
        if(flags[i]) {
            count += 1;
        }
    }

    return count;
}