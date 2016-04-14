/*
Write a program to find the first occurrence of a unique character in a string
For example, given a string: "aBcBcaAbBaAdAc", b and d are unique occurrences and b is the first one.

The approach:-
Count each occurrence of the characters. Also whenever it is first occurrence append it to an order array.
Traverse through order array to check for first occurrence of 1 in occurrence counter.
*/


#include <iostream>
#include <string>

using namespace std;

int main(){
	string s= "aBcBcaAbBaAdAc";
	
	char* charArray=new char[s.size()];
	int* countArray=new int[s.size()];
	for(int i=0; i<s.size();i++){
		countArray[i]=0;
		charArray[i]=' ';
	}

	int indexChar=0;
	int indexCount=0;
	bool found=false;
	
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			if(charArray[j]==s[i]){
				countArray[j]++;
				found=true;
				break;
			}
		}
		int j=0;
		if(!found){
			while(charArray[j]!=' ') j++;
			charArray[j]=s[i];
			countArray[j]=1;
		}
		found=false;

	}
	for(int i=0;i<s.size();i++){
		cout<<charArray[i]<<" ";
	}
	cout<<endl;
	int min=0;
	int i=0;
	while(countArray[i]>0){
		cout<<countArray[i]<<" ";
		if(countArray[min]>countArray[i] && countArray[i]>0) min=i;
		i++;
	}
	cout<<endl;
	cout<<"first min occurence: "<<charArray[min]<<endl;

	return 0;
}
