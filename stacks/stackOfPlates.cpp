/*
    Imagine a (literal) stack of plates. If the stack gets to high, it might topple. Therefore, in real life, we would likely start a new stack when the previous
    stack exceeds some threshold. Implement a data structure, SetOfStacks that mimics this. SetOfStacks should be composed of serveral stacks and should create a
    a new stack once the previous one exceeds the capacity. SetOfStacks.push() and SetOfStacks.pop() should behave incidentally to a single stack(this is pop()
    should return the same value it would if there were just a single stack)

    Follow up:
    Implement a function popAt(int index) which performs a pop operation on a specific sub-stack
*/

#include<bits/stdc++.h>

using namespace std;

// Set of Stacks Class
class SetOfStacks {
    private:
        int stackCapacity;
        int stackIndex;
        vector<stack<int> > setOfStacks;

    public:
        // Constructor for initializing the SetOfStack
        SetOfStacks() : stackCapacity(2), stackIndex(0) {
            setOfStacks.push_back(stack<int>());
        }

        void push(int ele) {
            // If the size of the setOfStacks is equal to stackCapacity, then push a new stack to the stack vector
            if(setOfStacks[stackIndex].size() == stackCapacity) {
                setOfStacks.push_back(stack<int>());
                stackIndex += 1;
                setOfStacks[stackIndex].push(ele);
            } else {
                setOfStacks[stackIndex].push(ele);
            }
        }

        void pop() {
            // If the stack at index 0 is empty then the remove it from the stack vector
            if(setOfStacks[stackIndex].empty()) {
                setOfStacks.pop_back();
                stackIndex -= 1;
                setOfStacks[stackIndex].pop();
            } else {
                // else pop the element from the stack present at the back of the vector
                setOfStacks[stackIndex].pop();
            }
        }

        void popAt(int index) {
            // pop element at particular index
            if(!setOfStacks[index].empty()) {
                setOfStacks[index].pop();
            } else {
                setOfStacks.erase(setOfStacks.begin() + index);
            }
        }

        int peek() {
            // Return the top most element of the stack
            return setOfStacks[stackIndex].top();
        }
};


int main() {
    SetOfStacks setOfStacks;
    setOfStacks.push(1);
    setOfStacks.push(2);
    setOfStacks.push(3);

    cout<<setOfStacks.peek()<<endl;

    setOfStacks.pop();
    setOfStacks.pop();

    cout<<setOfStacks.peek()<<endl;

}