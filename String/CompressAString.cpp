/*
Write a program to compress a string. If input is "aabbb"
expected output is "a2b3"
The approach:-
Have 2 pointers read and write to the input string.

Scan the string using read pointer.

If similar characters are seen keep incrementing a count.

If character sequence changes, write the character and the
count value at the write pointer.

Finally terminate the string with a null character.
*/

#include <iostream>
#include <string.h>

using namespace std;

int main(){
	char s[]="aabbbc";
	char* out=s;
	int outIndex=0;
	char ptr=s[0];
	int count=1;
	int i=1;
	while(s[i]!='\0'){
		if(ptr==s[i]){
			count++;
		}
		else{
			out[outIndex++]=ptr;
			out[outIndex++]=count+'0';
			ptr=s[i];
			count=1;
		}
		i++;
	}
	out[outIndex++]=ptr;
	out[outIndex++]=count+'0';
	out[outIndex++]='\0';
	cout<<out<<endl;
	return 0;
}


