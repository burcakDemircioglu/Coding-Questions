/*
Write a program to find the next number formed from permuting the digits in a given number
For example if the given number is 312, then the next number is 321 if you permute 1,2,3.
Start to looking at digits one by one from 1's digit towards left.
Check that digit value to its immediate left digit value. 
If that digit value is higher than the digit on the 
immediate left side of it, then stop. Let us say kth 
position digit is higher than (k+1)th position digit (K+1 is the place left of kth). 
Now look for digit on the visited list (all the k places)
 and find out a digit which is just higher than the (k+1)th digit. 
 Exchange those two digits and then place all the k digits in 
 increasing order (they are already in order but in decreasing). 
*/
#include <iostream>
#include <vector>
using namespace std;
const int MAX_SIZE=10;

int nextNumberWithPerm(int in){
	if(in<=9)return in;
	vector<int> buffer;
	int input=in;
	int right=input%10;
	buffer.push_back(right);
	input/=10;

	while(input>0){
		int left=input%10;
		
		if(left>right){
			right=left;
			buffer.push_back(left);
			input/=10;
		}
		else{
			for(int i=0; i<buffer.size();i++){
				if(buffer[i]>left){
					input-=left;
					input+=buffer[i];
					buffer[i]=left;
					break;
				}
			}
			for(int i=0; i<buffer.size();i++){
				input*=10;
				input+=buffer[i];
			}
			return input;
		}
	}
	return in;
}


int main(){
	int input=3987412;
	int out=nextNumberWithPerm(input);
	cout<<out<<endl;
	return 0;
}
