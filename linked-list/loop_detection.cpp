/*
    Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop
*/

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};



// Function to detect loop in a linked list
bool detectLoop(ListNode *head) {
    // Create a fast and slow pointer
    ListNode *slow = head;
    ListNode *fast = head;

    // If there exist a loop in the linked list, then fast and slow would meet at one point
    while(fast and fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        // If fast and slow point meets, then there exist a loop in the linked list
        if(fast == slow) {
            return true;
        }
    }

    // There is no loop in the linked list
    return false;
}