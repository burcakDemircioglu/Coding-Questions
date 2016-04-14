/*
Write a program to find if two strings are anagrams
Anagram - Wikipedia
An anagram is a type of word play, the result of rearranging
the letters of a word or phrase to produce a new word or phrase, 
using all the original letters exactly once; 
for example orchestra can be rearranged into carthorse.

The approach:-
1. Check string lengths.
2. Initialize a frequency table to keep count of characters seen.
3. Scan the first string and increment the frequency table.
4. Scan the second string and decrement the frequency table.
5. Check if the frequency table has count more than zero 
in any of the locations. If so, not an anagram. Else, anagram.
*/

#include <iostream>
#include <string>

using namespace std;

bool checkIfAnagram(string a, string b){
	if(a.size()!=b.size())return false;

	char* charArray=new char[a.size()];
	int* countArray= new int[a.size()];
	for(int i=0;i<a.size();i++){
		charArray[i]=' ';
		countArray[i]=0;
	}
	bool found=false;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.size();j++){
			if(charArray[j]==a[i]) {
				countArray[j]++;
				found=true;
				break;
			}
		}
		int j=0;
		if(!found){
			while(charArray[j]!=' ')j++;
			charArray[j]=a[i];
			countArray[j]=1;
		}
		found=false;
	}
	
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a.size();j++){
			if(charArray[j]==b[i]){
				countArray[j]--;
				found=true;
			}
		}
		if(!found) return false;

		found=false;
	}

	for(int i=0;i<a.size();i++){
		if(countArray[i]!=0) return false;
	}
	return true;
}

int main(){
	string a="burcakb";
	string b="bkacrub";
	bool anagram=checkIfAnagram(a,b);
	if(anagram)cout<<"Strings are anagram"<<endl;
	else cout<<"Strings are not anagram"<<endl;
	return 0;
}
