/*
Write a program to find the longest palindrome in a string
The approach:-
From each character location, compare the left and right locations for equality.

Remember the location and maximum size of equality.

Print the string starting from the location minus maximum size 
to location plus maximum size, which is the longest palindrome.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string getLongestPalindrom(string input){
	string palindrom;
	vector<string> palindroms;
	
	for(int i=0;i<input.size();i++){
		palindrom=input[i];
		for(int j=1;j<i;j++){
			if(i+j>=input.size())break;
			if(input[i+j]==input[i-j])
				palindrom=input[i+j]+palindrom+input[i+j];
			else break;
		}
		if(palindrom.size()>1)
			palindroms.push_back(palindrom);	
	}

	for(int i=0;i<palindroms.size();i++){
		cout<<palindroms[i]<<endl;
		if(palindrom.size()<palindroms[i].size())
			palindrom=palindroms[i];
	}
	return palindrom;
}


int main(){
	string input= "burcakakacurcak";
	string palindrom=getLongestPalindrom(input);
	cout<<"Longest palindrom in the string is: "<<palindrom<<endl;
	return 0;
}
