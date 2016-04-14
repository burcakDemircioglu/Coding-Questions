/*
Write a program to find the minimum depth of binary search tree 
and maximum depth of binary search tree
The approach:-
Depth is the height of a leaf node starting from the root.
Easiest approach is to have recursive function which finds 
the depth of left and write sub trees.
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

int findMinDepth(Node *root){
	if(root==NULL)return 0;
	int rightDepth=findMinDepth(root->right);
	int leftDepth=findMinDepth(root->left);
	if(rightDepth>=leftDepth)
		return leftDepth+1;
	else
		return rightDepth+1;
}


int findMaxDepth(Node *root){
	if(root==NULL)return 0;
	int rightDepth=findMinDepth(root->right);
	int leftDepth=findMinDepth(root->left);
	if(rightDepth<=leftDepth)
		return leftDepth+1;
	else
		return rightDepth+1;
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
	int min=findMinDepth(tree->root);
	int max=findMaxDepth(tree->root);

	cout<<"min:"<<min<<" max:"<<max<<endl;
	return 0;
}