/*
Write a program to convert decimal number to hexadecimal
The approach:-
Initialize a string array to hold the output hexadecimal string.

mod the input number by 16.  Map a hexadecimal digit based on the reminder value and append the output string.

Divide the number by 16 for next iteration.

Repeat steps 2 and 3 till number becomes 0.

Reverse the string to get the output hexadecimal sequence.
*/

#include <iostream>
#include <string>
using namespace std;



string turnIntToHex(int in){
	switch(in){
	case 10:
		return "A";
	case 11:
		return "B";
case 12:
		return "C";
case 13:
		return "D";
case 14:
		return "E";
case 15:
		return "F";
	default:
		return to_string(in);
}
}

string decimalToHex(int input){
	string out="";

	while(input!=0){
		int temp=input%16;
		input-=temp;
		out=turnIntToHex(temp)+out;
		input=input/16;
}
	return out;
}
int main(){
	int input=31;
	string hex=decimalToHex(input);
	cout<<hex<<endl;
	return 0;
}
