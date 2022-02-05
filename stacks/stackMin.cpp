/*
    Stack Min: How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, Pop and min should all
    operate in O(1) time
*/

#include<bits/stdc++.h>

using namespace std;


class MinStack {
    private:
        stack<pair<int, int> > minStack;

    public:
        // Constructor for initializing the stack
        MinStack() {}
        
        void push(int ele) {
            if(minStack.empty()) {
                // if the stack is empty, then the top element and minimum element would be ele
                pair<int, int> stackEle;
                stackEle.first = ele;
                stackEle.second = ele;
                minStack.push(stackEle);

            } else {
                // If the stack is not empty then the get the top element of the stack
                pair<int, int> topEle = minStack.top();
                pair<int, int> stackEle;

            
                stackEle.first = ele;
                stackEle.second = ele;

                // If the top minimum element is greater than the current element, then update the stack with top minimum element
                if(topEle.second > ele) {
                    minStack.push(stackEle);
                } else {
                    // Else push the element to the stack
                    stackEle.first = ele;
                    stackEle.second = topEle.second;
                    minStack.push(stackEle);
                }
            }
        }

        void pop() {
            // function which pops the element from the stack
            minStack.pop();
        }

        int getMin() {
            // function which gets the minimum element from the stack
            pair<int, int> topEle = minStack.top();
            return topEle.second;
        }

        int peek() {
            // function for getting the top most element of the stack
            pair<int, int> topEle = minStack.top();
            return topEle.first;
        }

};


int main() {
    MinStack minStack;
    minStack.push(1);
    minStack.push(2);
    minStack.push(3);
    minStack.push(4);

    cout<<minStack.peek()<<endl;
    cout<<minStack.getMin()<<endl;
    
}