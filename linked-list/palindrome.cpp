/*
    Implement a function to check if a linked list is a palindrome
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

ListNode *get_mid_node(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast and fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->next;
}
ListNode *reverse_list(ListNode *head) {
    ListNode *prev = nullptr;
    ListNode *next;
    ListNode *temp = head;
    while(temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head or !head->next) {
            return true;
        }
        ListNode *mid_node = get_mid_node(head);
        ListNode *reversedList = reverse_list(mid_node);

        while(reversedList) {
            if(reversedList->val != head->val) {
                return false;
            }
            reversedList = reversedList->next;
            head = head->next;
        }
        return true;
    }
};
