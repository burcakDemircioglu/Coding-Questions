/*
Write a program to do level order printing of a binary search tree with a new line after each level
The approach:-
As in the regular level order traversal we need a queue.

Push the root node into the queue and set the current level as 1.

When queue not empty dequeue a node and print the node and decrement the current level.

Push the left and right child if available and increment the next level.

If current level is zero print a new line and reset the current value to next level.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
	private:
	int value;	
	public:
		Node* right;
		Node* left;
		Node(int v){value=v; right=NULL; left=NULL;}
		int getValue(){return value;}
};

class bst{
	public:
	Node* root;
	bst(vector<int> array){
		root=new Node(array[0]);
		for(int i=1;i<array.size();i++){
			Node* ptr=root;
			while(true){
				if(array[i]<ptr->getValue()){
					if(ptr->left==NULL){
						ptr->left=new Node(array[i]);
						break;
					}
					else
						ptr=ptr->left;	
				}
				if(array[i]>ptr->getValue()){
					if(ptr->right==NULL){
						ptr->right=new Node(array[i]);
						break;
					}
					else
						ptr=ptr->right;
				}
			
			}
		}
	}

};


void printBst(bst *tree){
	queue<Node*> q;
	q.push(tree->root);
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
			cout<<q.front()->getValue()<<" ";
			if(q.front()->left!=NULL)
				q.push(q.front()->left);
			if(q.front()->right!=NULL)
				q.push(q.front()->right);
			q.pop();
		}
		cout<<endl;
	}

}

int main(){
	vector<int> list;
	list.push_back(4);
	list.push_back(2);
	list.push_back(6);
	list.push_back(1);
	list.push_back(3);
	list.push_back(5);
	list.push_back(7);

	bst* tree=new bst(list);
	printBst(tree);
	return 0;
}