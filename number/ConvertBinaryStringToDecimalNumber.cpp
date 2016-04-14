/*
Write a program to convert binary string to decimal number
Parse the input string till end. On encountering a "1" compute 
power of 2 for the current position and add to a variable holding the result.
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

double convertToDecimal(string input){
	double out=0;
	bool decimal=false;
	int dotIndex;
	int index=input.size()-1;
	while(index>=0){
		if(input[index]=='.'){ 
			decimal=true;
			dotIndex=index;
			break;
		}
		index--;
	}

	string left="";
	string right="";
	
	if(!decimal)
		left=input;
	else{
		for(int i=0;i<dotIndex;i++)
			left+=input[i];
		for(int i=dotIndex+1;i<input.size();i++)
			right+=input[i];
	}

	index=left.size()-1;
	while(index>=0){
		out+=pow(2,left.size()-(index+1))*(left[index]-'0');
		index--;
	}

	if(decimal){
		index=0;
		while(index<right.size()){
			out+=pow(2, -(index+1))*(right[index]-'0');
			index++;
		}

	}

	return out;
}

int main(){
	string input="1010.111";
	double out=convertToDecimal(input);
	cout<<out<<endl;
	return 0;
}
