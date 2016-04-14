/*
Hexadecimal string to decimal number

Write a program to convert hexadecimal string to decimal number.
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;
int hexStringtoInt(char a){
	switch(a){
		case 'A':
			return 10;
		case 'B':
			return 11;
		case 'C':
			return 12;
		case 'D':
			return 13;
		case 'E':
			return 14;
		case 'F':
			return 15;
		default:
			return a-'0';
	}

}
int hextoInt(string input){
	int out=0;
	for(int i=input.size()-1;i>=0;i--){
		out+=pow(16,(input.size()-1-i))*hexStringtoInt(input[i]);
}
	return out;
}
int main(){
	string hexInput="2F";
	int out=hextoInt(hexInput);
	cout<<out<<endl;
	return 0;
}
