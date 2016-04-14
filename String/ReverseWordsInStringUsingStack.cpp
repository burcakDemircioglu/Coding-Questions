/*
Write a program to reverse words of a string using a stack
The simplest approach to reverse words of a string is using a stack.
To understand more about stack data structure refer C++ Stacks. 
Detect end of words and push into the stack. 
Then parse the contents of stack and print to get the string reversed.
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseString(string s){
	string out=s;
	stack<char> charStack;
	int j=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==' '){
			while(!charStack.empty()){
				out[j++]=charStack.top();
				charStack.pop();
			}
			out[j++]=' ';
		}
		else
			charStack.push(s[i]);
	}
	while(!charStack.empty()){
				out[j++]=charStack.top();
				charStack.pop();
			}
	return out;
}


int main(){
	string s="burcak is coming";
	s=reverseString(s);
	cout<<s<<endl;
	return 0;
}
