/*
    Intersection: Given two singly linked list, determine if the two linked list intersect. Return the intersecting node. Note that the intersection is defined by the
    referenc, not value. That is, if Kth node of the first linked list is the exact same node (by reference) as the jth node the second list, then they are intersecting.
*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

// Function to get the lenght of a linked list
int getLength(ListNode *head) {
    // Fast and slow pointer poiting to the head of the linked list
    ListNode *slow = head;
    ListNode *fast = head;
    
    // Variable for storing the length of the linked list
    int length = 0;

    // Using fast and slow pointer technique to get the length of the linked list
    while(fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        length += 1;
    }

    // If the fast is nullptr, then the length of the list would be length * 2
    if(!fast) {
        return length * 2;
    } else {
        return (length + 1) * 2;
    }
}


ListNode* getIntersectedNode(ListNode *head1, ListNode *head2) {
    // Get the length of the input linked list
    int length1 = getLength(head1);
    int length2 = getLength(head2);

    // If the second list has more nodes, get it diff times ahead
    if(length2 > length1) {
        int diff = length2 - length1;
        while(diff > 0) {
            head2 = head2->next;
        }
    } else {
        // If the first list has more nodes, get it diff times ahead
        int diff = length1 - length2;
        while(diff > 0) {
            head1 = head1->next;
        }
    }

    // Iterate and check if the head1 of a the linked list is equal to head2 of the linked list then the lists are intersecting
    while(head1 and head2) {
        if(head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return nullptr;
}