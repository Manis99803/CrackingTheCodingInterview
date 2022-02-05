/*
    Write a program to sort a stack such taht the smallest items are on top. You can use an additional temporary stack but you may not copy the elements 
    into another data structure(such as an array). THe stack supports the following operations push, pop, peek and isEmpty
*/

#include<bits/stdc++.h>

using namespace std;

// Function to sort stack
void sortStack(stack<int> &st) {
    // temporary stack to be utilized for sorting the input stack
    stack<int> tempStack;

    while(!st.empty()) {
        int top = st.top();
        st.pop();
        if(tempStack.empty()) {
            tempStack.push(top);
        } else {
            while(!tempStack.empty() and top > tempStack.top()) {
                st.push(tempStack.top());
                tempStack.pop();
            }
            tempStack.push(top);
        }
    }

    while(!tempStack.empty()) {
        cout<<tempStack.top()<<endl;
        tempStack.pop();
    }
}

int main () {
    stack<int> st;
    st.push(4);
    st.push(3);
    st.push(1);
    st.push(2);
    st.push(5);

    sortStack(st);

}
