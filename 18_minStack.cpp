#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class MinStack{

public:
MinStack() {

}

void push(int val) {
  m_stack.push(val);
  if(min_stack.empty())
    min_stack.push(val);
  else
    min_stack.push(std::min(val,min_stack.top()));
}

void pop() {
  m_stack.pop();
  min_stack.pop();
}

int top() {
  return m_stack.top();
}

int getMin() {
  return min_stack.top();
}

private:
    stack<int> m_stack;
    stack<int> min_stack;
};

int main(){
 MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  minStack.getMin(); // return -3
  minStack.pop();
  minStack.top();    // return 0
  minStack.getMin(); // return -2

  return 0;
}
