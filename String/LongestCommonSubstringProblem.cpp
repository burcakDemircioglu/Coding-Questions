/*
Write a program to find the longest common sub-string of two given strings
The approach:-
Key to the LCS problem is to generate a LCS matrix based on which 
the longest common sub-string could be derived.
There is a cool video explaining the LCS matrix construction from 
Jay Liew, Security Researcher @ Websense Security Labs.
https://youtu.be/RUckZMzqUcw
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printMatrix(int** m, int sizeA, int sizeB){
	for(int i=0;i<sizeA;i++){
		for(int j=0;j<sizeB;j++){
			cout<<m[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

vector<string> longestSubString(string a, string b){
	vector<string> sub;
	int max=0;
	//initialize the matrix
	int **matrix=new int*[a.size()];
	for(int i=0;i<a.size();i++){
		matrix[i]=new int[b.size()];
		for(int j=0;j<b.size();j++)
			matrix[i][j]=0;
	}
	
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			if(a[i]==b[j]){
				if(i==0 || j==0){
					matrix[i][j]++;
				}
				else
					matrix[i][j]=matrix[i-1][j-1]+1;
				if(matrix[i][j]>max){
					max=matrix[i][j];
					//empty the sub
					sub.clear();
				}
				if(matrix[i][j]==max){
					string newSub;
					int backTraceX=i;
					int backTraceY=j;
					while(matrix[backTraceX][backTraceY]!=1){
						backTraceX--;
						backTraceY--;
					}
					while(matrix[backTraceX][backTraceY]!=max){
						newSub+=a[backTraceX];
						backTraceX++;
						backTraceY++;
					}
					newSub+=a[backTraceX];

					// backtrace and insert the new substring
					newSub+='\0';
					sub.push_back(newSub);
				}
			}
		}
	}
	printMatrix(matrix, a.size(), b.size());
	cout<<"Max Substring Size is: "<<max<<endl;

	return sub;
}


int main(){
	string a = "clcl";
	string b="lclc";
	vector<string> sub=longestSubString(a,b);

	cout<<"longestSubStrings: ";
	for(int i=0;i<sub.size();i++){
		cout<<sub[i];
		if(i!=sub.size()-1)cout<<", ";
	} 
	cout<<endl;
	return 0;
}
