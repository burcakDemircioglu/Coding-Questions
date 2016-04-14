/*
Write a program to find least common ancestor (lca) of 2 nodes in a binary search tree
The approach:-
Starting from the root node.

Check if the node key is between the two provided keys. 
If so, the current node is the least common ancestor.

If the two provided keys are greater than the current 
node then recursively search the right sub-tree.

If the two provided keys are less than the current node then 
recursively search the left sub-tree.
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

Node* findLca(Node* root, int n1, int n2){
	Node* ptr=root;
	if(root->getValue()>=n1 && root->getValue()<=n2) return root;

	if(root->getValue()>n2)return findLca(root->left, n1, n2);
	if(root->getValue()<n1)return findLca(root->right, n1, n2);
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
	int out=findLca(tree->root, 1,3)->getValue();
	cout<<out<<endl;
	return 0;
}
