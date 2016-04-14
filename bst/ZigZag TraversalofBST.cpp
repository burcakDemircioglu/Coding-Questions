/*
Write a program to do zig zag traversal of a binary search tree
The approach:- 
Need assistance of a queue.
Same as level order traversal except that instead of pushing 
the left sub-tree into the queue first push the right tree sub-tree.
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
			
			if(q.front()->right!=NULL)
				q.push(q.front()->right);
			if(q.front()->left!=NULL)
				q.push(q.front()->left);
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
	cout<<endl;
	int out=0;
	cout<<out<<endl;
	return 0;
}