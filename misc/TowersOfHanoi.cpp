/*
Approach to solve the Towers of Hanoi game

We need to move the n rings from the first pole to target third pole using the second pole as buffer.

First move the n-1 rings from first to a second pole using the third.

Then move the remaining big ring from first to the third.

Now move all the n-1 rings from the second pole to the target third pole on top of the nth (which is big).

For moving the n-1 rings from one pole to another pole, use the remaining pole as a buffer using recursion.
*/

#include <iostream>
#include <stdio.h>

int from[4]={4,3,2,1};
int to[4]={0};
int temp[4]={0};

using namespace std;

void print(){
	cout<<endl;
	for(int i=3;i>=0;i--)
		cout<<"["<<from[i]<<"]["<<temp[i]<<"]["<<to[i]<<"]"<<endl;
}

void move(int from[], int to[]){
	int i,j;
	for(i=0;i<4;i++)
		if(from[i]==0)break;
	for(j=0;j<4;j++)
		if(to[j]==0)break;

	to[j]=from[i-1];
	from[i-1]=0;
	print();
}

void play(int f[] , int tmp[], int t[], int n){
	if(n==0)return;
	play( f, t, tmp, n-1);
	move(f,t);
	play(tmp, f, t, n-1);
}

int main(){
	play(from, temp, to, 4);	
}

