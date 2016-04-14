/*

Write a program to rotate a matrix by 90 degrees
e.g)
Input:-
1 2 3
4 5 6
7 8 9

Output:-
7 4 1
8 5 2
9 6 3
Approach to rotate a matrix by 90 degrees

First we transpose the matrix and swap the columns to rotate the matrix by 90 degrees.
1) Transpose the matrix.
1 4 7
2 5 8
3 6 9

2) Swap the columns.
7 4 1
8 5 2
9 6 3

*/

#include <iostream>
#include <stdio.h>

using namespace std;

void printMatrix(int **m, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++)
			cout<<m[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void getTranspose(int **m, int size){
	for(int i=0;i<size;i++){
		for(int j=i;j<size;j++){
			if(i!=j){
				int temp=m[i][j];
				m[i][j]=m[j][i];
				m[j][i]=temp;
			}
		}
	}
	cout<<"Transpose:"<<endl;
	printMatrix(m, 3);
}

void turnMatrixNinty(int **m, int size){
	getTranspose(m, size);
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size/2;j++){
			int temp=m[i][j];
			m[i][j]=m[i][size-1-j];
			m[i][size-1-j]=temp;
		}
	}
}

int main(){
	//for testing purposes
	int **matrix=new int*[3];
	for(int i=0;i<3;i++)
		matrix[i]=new int [3];

	int count=1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			matrix[i][j]=count++;
	}
	cout<<"Original:"<<endl;
	printMatrix(matrix, 3);
	turnMatrixNinty(matrix, 3);
	cout<<"Turned:"<<endl;
	printMatrix(matrix, 3);
	for(int i=0;i<3;i++)
		delete matrix[i];
	return 0;
}
