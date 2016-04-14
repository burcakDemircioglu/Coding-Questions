/*
Find the number occurring odd number of times

There is an array of numbers, where each number occurs 
even number of times except for one number which occurs 
odd number of times. Find out the number.

When you XOR a number even number of times, it becomes zero. 
So XOR all the numbers in the array, the result will be 
the number which occurred odd times.
*/

#include <iostream>

using namespace std;

int main(){
	int array[9]={3,15,67,36,3,15,36,567,567};
	int out=0;
	
	for(int i=0;i<sizeof(array)/sizeof(array[0]);i++)
		out^=array[i];
	cout<<out<<endl;
	return 0;
}
