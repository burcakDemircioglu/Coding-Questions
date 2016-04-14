/*
Find number of prime numbers below a given number
One could test for prime, from 4 till the given number 
and count those numbers. This does not need extra memory 
but slow. Below we provide solution which is fast but needs memory. 
This is using Sieve of Eratosthenes method.

Approach:-
Have a memory allocated for ints up-to given input
Run a counter from 2 till the given number. And for each number, 
mark down the multiples of it as non-primes in the int array 
allocated (ignoring that number, i.e. x1).
Unmarked ones are not the multiples of any number and hence primes
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> findPrimesUnder(int input){
	vector<bool> ifPrime;
	vector<int> out;

	for(int i=0;i<=input;i++)
		ifPrime.push_back(true);
	
	int number=0;
	for(int i=2;i<=input;i++){
		number=i;
		int j=i;
		while(number<=input){
			number=i;
			number=number*(j++);
			ifPrime[number]=false;
		}
	}
	for(int i=2;i<=input;i++)
		if(ifPrime[i]) out.push_back(i);

	return out;
}

int main(){
	int input=200;
	vector<int> out=findPrimesUnder(input);
	for(int i=0;i<out.size();i++){
		cout<<out[i]<<" ";
	}
	cout<<endl;
	return 0;
}
