/*
Write a program to reverse words of a string without using stack
The approach:-
Reverse the entire string.

Scan the string from beginning.

On reaching a word (space) reverse the sub string. Continue till end of the string.
*/

#include <iostream>
#include <string>

using namespace std;
string reverseWordsInString(string s){
	string out=s;
	int index=0;
	int wordStart=0;
	
	for(int i=0;i<=s.size();i++){
		if(s[i]==' '|| s[i]=='\0'){
			for(int j=i-1;j>=wordStart;j--){
				out[index++]=s[j];
			}
			out[index++]=' ';
			wordStart=i+1;
		}
	}
	return out;
}
int main(){
	string s="burcak is coming";
	s=reverseWordsInString(s);
	cout<<s<<endl;
return 0;
}
