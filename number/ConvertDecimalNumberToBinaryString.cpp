/*
Write a program to convert decimal number to binary string
The approach:-
Initialize a string array to hold the output binary string.

mod the input number by 2.  If reminder is '1' include '1' in the output string. Else include '0'.

Divide the number by 2 for next iteration.

Repeat steps 2 and 3 till number becomes 0.

Reverse the string to get the output sequence.
*/

#include <iostream>
#include <string>

using namespace std;

string convertToBinary(double input){
	int left=(int)input;
	double right=input-left;
	string out;
	int temp;
	while(left!=0){
		temp=left%2;
		left=left-temp;
		left=left/2;
		out=to_string(temp)+out;
	}
	if(right!=0)
		out+=".";
	
	while(right!=0){
		right=right*2;
		if(right>=1){
			out+="1";
			right=right-1;
		}
		else out+="0";
	}
	return out;
}

int main(){
	double input=9.25;
	string binary=convertToBinary(input);
	cout<<binary<<endl;
	return 0;
}
