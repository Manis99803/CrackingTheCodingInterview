/*
    Delete Middle Node: Implement an algorithm to delete a node in the middle (i.e, any node but the first and last node, node necessarily the exact middle)
    of a singly linked list, given only access to that node.

    Ex: Input: a->b->c->d->e->f
    Output: a->b->d->e->f
*/

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *deleteMiddleNode(Node *head) {
    // If the head is null or the linked list has only one node, then return the nullptr
    if(!head or !head->next) {
        return nullptr;
    }

    // We will be using the fast and slow pointer concept to find the middle node
    Node *slow = head;
    Node *fast = head;
    Node *prev = nullptr;

    // Iterate and get the middle node
    while(fast and fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    
    // point the previoud node the next of slow node
    prev->next = slow->next;
    return head;
}

