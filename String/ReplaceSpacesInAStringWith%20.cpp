/*
Write a program to replace spaces in a string with %20
Approach to replace spaces in a string with %20

Typically in this problem we are expected to use optimal memory. 
This requires that we extend the memory where we hold the input string. 
We start by counting the number of spaces in the input string. 
Then we compute the new size required (2 * spacecount + length) and 
extend the input string for the extra space required. 
As the final step scan the input string from the last and if a 
space is encountered insert %20. That way we use memory optimally 
and don't overrun the input string.
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	string input="my name is burcak";
	int spaceCount=0;
	int originalSize=input.length();
	for(int i=0;i<originalSize;i++){
		if(input[i]==' ')
			spaceCount++;
	}
	int newSize=originalSize+spaceCount*2;
	input.resize(newSize, ' ');

	int iterator=newSize-1;

	for(int i=originalSize-1;i>=0;i--){
		if(input[i]!=' ')
			input[iterator--]=input[i];
		else{
			input[iterator--]='0';
			input[iterator--]='2';
			input[iterator--]='%';
		}
	}
	cout<<input<<endl;
	return 0;
}
