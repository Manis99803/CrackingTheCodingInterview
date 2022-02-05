/*
    Queue via stacks: Implement a MyQueue class which implements a queue using two stacks
*/

#include<bits/stdc++.h>

using namespace std;

class MyQueue {
    private:
        stack<int> s1;
        stack<int> s2;

    public:
        // MyQueue Constructor class
        MyQueue() {}

        void push(int ele) {
            // Function for adding the elements to the queue
            if(s1.empty()) {
                s1.push(ele);
            } else {
                while(!s1.empty()) {
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.push(ele);
                while(!s2.empty()) {
                    s1.push(s2.top());
                    s2.pop();
                }
            }
        }

        void pop() {
            // remove the queue element
            s1.pop();
        }

        int front() {
            // get the first item of the queue
            return s1.top();
        }
};


int main() {
    MyQueue myqueue;
    myqueue.push(1);
    myqueue.push(2);
    myqueue.push(3);

    cout<<myqueue.front()<<endl;

}