/*
Write a program to transpose a matrix
e.g.) Input matrix.
1  2  3
4 5 6
7 8 9

Transposed matrix.
1 4 7
2 5 8
3 6 9
*/

#include <iostream>
#include <stdio.h>

using namespace std;

void transpose(int **matrix, int size){
	for(int i=0;i<size;i++){
		for(int j=i;j<size;j++){
			if(i!=j){
				int temp=matrix[i][j];
				matrix[i][j]=matrix[j][i];
				matrix[j][i]=temp;
				}
		}
	}
}

void printMatrix(int **matrix, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	//for testing purposes
	int size=3;
	int **matrix=new int*[size];
	int count =1;
	for(int i=0;i<size;i++)
		matrix[i]=new int[size];
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			matrix[i][j]=count++;
	}
	cout<<"Initial Matrix:"<<endl;
	printMatrix(matrix, size);
	cout<<endl;
	transpose(matrix,size);
	cout<<"Transposed Matrix:"<<endl;
	printMatrix(matrix, size);
	for(int i=0;i<size;i++)
		delete matrix[i];
	return 0;
}
