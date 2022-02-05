/*
    Sum Lists: You have two numbers represented by a linked list, where each node contains a single digit. The digit are in reverse order, such that
    1's digit is at the head of linked list. Write a function that adds the two numbers and returns the sum of a linked list
*/


#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *sumList = new ListNode(-1);
    ListNode *sumListHead = sumList;
    int carry = 0;
    int sum = 0;
    
    while(l1 and l2) {
        sum = l1->val + l2->val + carry;
        if(sum > 9) {
            carry = sum / 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }
        sumList->next = new ListNode(sum);
        sumList = sumList->next;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(l1) {
        sum = l1->val + carry;
        if(sum > 9) {
            carry = sum / 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }
        sumList->next = new ListNode(sum);
        sumList = sumList->next;
        l1 = l1->next;
    }
    
    while(l2) {
        sum = l2->val + carry;
        if(sum > 9) {
            carry = sum / 10;
            sum = sum % 10;
        } else {
            carry = 0;
        }
        sumList->next = new ListNode(sum);
        sumList = sumList->next;
        l2 = l2->next;
    }
    
    if(carry > 0) {
        sumList->next = new ListNode(carry);
        sumList = sumList->next;
    }
    return sumListHead->next;
}