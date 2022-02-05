/*
    Return Kth to last: Implement an algorithm to find the kth last element of a singly linked list
*/

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};


int getNthFromLast(Node *head, int n) {
    // Point the slow and fast pointer to head
    Node *slow = head;
    Node *fast = head;

    // Move the fast pointer to n steps ahead
    while(n > 0 and fast) {
        fast = fast->next;
        n -= 1;
    }

    // If the fast pointer has reached the end and n is not 0, return -1
    if(!fast and n > 0) {
        return -1;
    } else if(fast and n == 0) {
        // If n == 0 and fast pointer has reached to end, then the node is first node
        return head->data;
    } else {
        // Else get the node pointed by slow pointer
        while(fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow->data;
    }
}