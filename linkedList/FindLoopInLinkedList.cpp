/*
Find a loop in linked list and identify the looped node

A linked list has tail joined back in to the list forming a loop. Identify the looped node. 
For example A->B->C->D->E->F->G->H->I-NULL, has been modified so that I's next is pointing 
to, let us say D. Task is to identify D. Alternatively, another question would be to find 
I and set it's next to NULL to correct the linked list.

Approach to find a loop in a linked list

First identify the loop (using fast and slow pointer method). Thereby identifying a node in the loop

Find the loop length.

Now start two pointers one at the head (first) of the list and another (second) at the node at loop 
length distance from head. Increment both simultaneously until they meet each other. 
If A is the length from head to the looped node and B is the loop length. A+B is the length 
of original linked list. Hence when the second moves by B+A length, the first one would have 
moved by A and hence they meet each other.
If you don't have to find the loop length, or otherwise one could start one pointer to head and 
the second (faster pointer) start from where they met. This time second pointer moving at the 
same speed at the first one (-->see findJoinedNode function). findJoinedNode works better than 
the findJoinedNodeWithLoopLength.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class Node{
	private:
	int value;
	public:
	Node* next;
	Node(){next=NULL;value=0;};
	Node(int v){value=v;next=NULL;};
	int getValue(){return value;};
};
class List{
	public:
	Node* head;
	List(){head=NULL;};
	void addNode(int value){
		Node* node=new Node(value);
		if(head==NULL)
			head=node;
		else{
			node->next=head;
			head=node;
		}
	};
};

Node* findLoopStart(Node* node){
	Node* ptr1=node->next;
	Node* ptr2=node->next->next;

	while(ptr1!=ptr2){
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
	}
	ptr1=node;

	while(ptr1!=ptr2){
		ptr1=ptr1->next;
		ptr2=ptr2->next;
	}
	return ptr1;
}

void loopFix(Node* node, Node* loopNode){
	Node* ptr=node;
	if(ptr!=loopNode){
		while(loopNode!=ptr->next){
			ptr=ptr->next;
		}
		ptr=ptr->next;
		while(loopNode!=ptr->next){
			ptr=ptr->next;
		}
		ptr->next=NULL;	
	}
}
void print(Node* head){
	while(head!=NULL){
		cout<<head->getValue()<<" ";
		head=head->next;
	}
	cout<<endl;
}
int main(){
	Node* node1=new Node(1);
	Node* node2=new Node(2);
	Node* node3=new Node(3);
	Node* node4=new Node(4);
	Node* node5=new Node(5);
	Node* node6=new Node(6);
	node1->next=node2;
	node2->next=node3;
	node3->next=node4;
	node4->next=node5;
	node5->next=node6;
	node6->next=node4;


	Node* loopStarterNode=findLoopStart(node1);
	cout<<"loopStartNode: "<<loopStarterNode->getValue()<<endl;
	loopFix(node1, loopStarterNode);
	print(node1);
	return 0;

}
