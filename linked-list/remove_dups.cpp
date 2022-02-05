/*
    Remove Dups: Write code to remove duplicates from an unsorted linked list
    
    Follow up:
    - How would you solve this if a temporary buffer is not allowed?
*/

#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *removeDuplicates(Node *head) {
    if(!head) {
        return nullptr;
    }

    unordered_map<int, int> nodeMap;
    Node *curr = head, *prev;

    while(curr) {
        if(nodeMap.find(curr->data) == nodeMap.end()) {
            nodeMap[curr->data] = 1;
            prev = curr;
        } else {
            prev->next = curr->next;
        }
        curr = curr->next;
    }

    return head;
}

