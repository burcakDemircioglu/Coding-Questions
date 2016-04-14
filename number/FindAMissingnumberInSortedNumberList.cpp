/*
You are given a sorted number list from 0 to n. 
The list is missing one number, find out that number

We can run a binary search. Check the value in the middle, 
and see if the index of it is same as the value. If it is not, 
then 0 to mid range has a missing number, search in that range. 
Otherwise search in the range mid+1 to n. Continue similarly 
reducing the range by half every time, until you find the missing number.
*/

#include <iostream>


using namespace std;

int binarySearch(int array[], int start, int end){
	int indexMiddle=(end-start)/2+start;
	//cout<<"start: "<<start<<" end: "<<end<<" middle: "<<indexMiddle<<endl;

	if(start==end) return array[start];
	if(indexMiddle==start){
		if(array[indexMiddle]!=indexMiddle) return indexMiddle;
		if(array[end]!=end) return end;
	}
	if(array[indexMiddle]==indexMiddle)
		return binarySearch(array, indexMiddle, end);
	else	
		return binarySearch(array, start, indexMiddle);
}

int findMissingInt(int array[], int size){
	return binarySearch(array, 0, size);
}

int main(){
	int array[5]={0,1,3,4,5};
	int size=sizeof(array)/sizeof(array[0]);
	int missing=findMissingInt(array, size);
	cout<<missing<<endl;
	return 0;
}
