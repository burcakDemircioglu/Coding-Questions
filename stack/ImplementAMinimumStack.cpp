/*
Write a program to implement a stack that can return a minimum 
value of the current elements at any instance
The Approach:-
Have a second stack instance which will hold the minimum values.

During a push operation if the new data is smaller than the top value 
in minimum stack push the data into the minimum stack.

During a pop operation if the popped out value is same as top value 
in minimum stack pop the top element from minimum stack.

At any given instance the top element in the minimum stack is the 
minimum value of all elements in the stack.
*/

#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

class minStack{
private:
	stack<int> s;
	stack<int> minS;
public:
	minStack(){};
	int getMin(){
		if(!minS.empty())
			return minS.top();
		else
			return -1;
	}
	void push(int value){
s.push(value);
if(minS.empty())
minS.push(value);
else{
	if(minS.top()>=value)
		minS.push(value);
}
}
void pop(){
	if(!s.empty()){
		int value=s.top();
		s.pop();
		if( minS.top()==value)
		minS.pop();
	}
	
}
};

int main(){
	//for testing purposes..
	minStack s;
	s.push(5);
	cout<<"min value in stack after push:"<<s.getMin()<<endl;
	s.push(6);
	cout<<"min value in stack after push:"<<s.getMin()<<endl;
	s.push(4);
	cout<<"min value in stack after push:"<<s.getMin()<<endl;
	s.push(1);
	cout<<"min value in stack after push:"<<s.getMin()<<endl;
	s.pop();
	cout<<"min value in stack after pop:"<<s.getMin()<<endl;
	s.pop();
	cout<<"min value in stack after pop:"<<s.getMin()<<endl;
	s.pop();
	cout<<"min value in stack after pop:"<<s.getMin()<<endl;
	s.pop();
	cout<<"min value in stack after pop:"<<s.getMin()<<endl;
	return 0;
}
